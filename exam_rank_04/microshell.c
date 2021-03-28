#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> //linux

typedef struct		s_cmd
{
	char			**agrs;
	int				fd[2];
	int				is_pipe;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

int		ft_strlen(char *s)
{
	int i = 0;
	while (s && s[i]) i++;
	return i;
}

void	ft_putstr(char *s)
{
	write(2, s, ft_strlen(s));
}

void	fatal_exit(void)
{
	ft_putstr("error: fatal\n");
	exit(1);
}

char	*ft_strdup(char *s)
{
	int i = 0;
	char *ret = 0;

	if (!(ret = malloc(ft_strlen(s) + 1)))			fatal_exit();
	for (i = 0; s[i]; i++)
		ret[i] = s[i];
	ret[i] = 0;
	return ret;
}

void	lst_clear(t_cmd *cmds)
{
	t_cmd *tmp = 0;

	while (cmds)
	{
		for (int i = 0; cmds->agrs[i]; i++)
			free(cmds->agrs[i]);
		free(cmds->agrs);
		tmp = cmds;
		cmds = cmds->next;
		free(tmp);
	}
}

t_cmd	*create_cmd(t_cmd *tmp, char **av, int av_len, int is_pipe)
{
	t_cmd	*new = 0;
	int		i = 0;

	if (!(new = malloc(sizeof(t_cmd))))							fatal_exit();
	if (!(new->agrs = malloc(sizeof(char*) * (av_len + 1))))	fatal_exit();
	for (i = 0; i < av_len; i++)
		new->agrs[i] = ft_strdup(av[i]);
	new->agrs[i] = 0;
	new->is_pipe = is_pipe;
	new->prev = tmp;
	new->next = 0;
	if (tmp)
		tmp->next = new;
	return new;
}

int		ft_cd(t_cmd *cmds)
{
	int		i = 0;
	int		ret = 0;

	while (cmds->agrs[i]) i++;
	if (i != 2)
	{
		ft_putstr("error: cd: bad arguments\n");
		return 1;
	}
	else if ((ret = chdir(cmds->agrs[1])) < 0)
	{
		ft_putstr("error: cd: cannot change directory to ");
		ft_putstr(cmds->agrs[1]); ft_putstr("\n");
	}
	return ret;
}

int		exec_cmds(t_cmd *cmds, char **env)
{
	int		wstatus = 0;
	int		pid = 0;
	int		ret = 0;

	if (cmds->is_pipe)
		if (pipe(cmds->fd) < 0)
			fatal_exit();
	pid = fork();
	if (pid < 0)
		fatal_exit();
	else if (pid == 0)
	{
		if (cmds->is_pipe && dup2(cmds->fd[1], 1) < 0)							fatal_exit();
		if (cmds->prev && cmds->prev->is_pipe && dup2(cmds->prev->fd[0], 0) < 0)		fatal_exit();
		if ((ret = execve(cmds->agrs[0], cmds->agrs, env)) < 0)
		{
			ft_putstr("error: cannot execute ");
			ft_putstr(cmds->agrs[0]); ft_putstr("\n");
		}
		exit(ret);
	}
	else if (pid > 0)
	{
		waitpid(pid, &wstatus, 0);
		if (WIFEXITED(wstatus))
			ret = WEXITSTATUS(wstatus);
		if (cmds->is_pipe)
		{
			close(cmds->fd[1]);
			if (!cmds->next)
				close(cmds->fd[0]);
		}
		if (cmds->prev && cmds->prev->is_pipe)
			close(cmds->prev->fd[0]);
	}
	return ret;
}

int		exec(t_cmd *cmds, char **env)
{
	int ret = 0;

	while (cmds)
	{
		if (!strcmp("cd", cmds->agrs[0]))
			ret = ft_cd(cmds);
		else
			ret = exec_cmds(cmds, env);
		cmds = cmds->next;
	}
	return ret;
}

int		main(int ac, char **av, char **env)
{
	int		start = 1;
	int		last = 1;
	int		ret = 0;
	int		is_pipe = 0;
	t_cmd	*tmp = 0;
	t_cmd	*cmds = 0;

	while (last < ac)
	{
		if (!strcmp("|", av[last]) || !strcmp(";", av[last]) || last + 1 == ac)
		{
			if (!strcmp("|", av[last]))						is_pipe = 1;
			else if (!strcmp(";", av[last]))				is_pipe = 0;
			else{
				is_pipe = 0;
				last++;
			}
			if (last - start != 0)
			{
				tmp = create_cmd(tmp, &av[start], last - start, is_pipe);
				if (!cmds)
					cmds = tmp;
			}
			start = last + 1;
		}
		last++;
	}
	ret = exec(cmds, env);
	lst_clear(cmds);
	return ret;
}
