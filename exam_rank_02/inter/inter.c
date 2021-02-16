#include <unistd.h>

int		main(int ac, char **av)
{
	char	used[255] = {0};
	int		j = 0;

	if (ac == 3)
	{
		while (av[2][j])
			used[(unsigned char)av[2][j++]] = 1;
		j = 0;
		while (av[1][j])
		{
			if (used[(unsigned char)av[1][j]] == 1)
			{
				write(1, &av[1][j], 1);
				used[(unsigned char)av[1][j]] = 2;
			}
			j++;
		}
	}
	write(1, "\n", 1);
}
