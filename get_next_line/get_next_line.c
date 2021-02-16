#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int		i = 0;
	if (!s) return (0);
	while (s[i]) i++;
	return (i);
}

int		resize(char **line, int len)
{
	int		i = 0;
	char	*ret = malloc(len + BUFFER_SIZE + 1);

	while (i < len)
	{
		ret[i] = (*line)[i];
		i++;
	}
	ret[i] = 0;
	free(*line);
	*line = ret;
	return 1;
}

int		remind(char buf[], char **line)
{
	int		i = ft_strlen(*line);
	int		j = 0;
	int		ret = 0;

	if (!resize(&(*line), i)) return (0);
	while (buf[j])
	{
		(*line)[i++] = buf[j];
		if (buf[j++] == '\n')
		{
			i--;
			ret = 1;
			break ;
		}
	}
	(*line)[i] = 0;
	i = 0;
	while (buf[j])
		buf[i++] = buf[j++];
	buf[i] = 0;
	return (ret);
}

int		error(char **line)
{
	free(*line);
	*line = 0;
	return -1;
}

int		get_next_line(char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int		rest = 0;
	int		size = 0;

	if (!line) return (-1);
	*line = 0;

	if ((rest = remind(buf, &(*line)))) return (rest);
	while ((size = read(0, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = 0;
		if ((rest = remind(buf, &(*line)))) return (rest);
	}
	if (size == -1) return (error(line));
	return (size);
}
