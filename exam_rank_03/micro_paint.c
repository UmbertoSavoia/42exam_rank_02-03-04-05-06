#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct	s_b
{
	int		width;
	int		height;
	char	c;
	char	*matrix;
}				t_b;

typedef struct	s_r
{
	char	type;
	float	start_x;
	float	start_y;
	float	width;
	float	height;
	char	color;
}				t_r;

t_b		g_b;
t_r		g_r;

int		ft_puterror(char *s, int fr)
{
	int		i = 0;

	while (s && s[i]) i++;
	write(1, s, i);

	if (fr) free(g_b.matrix);

	return (1);
}

int		main(int argc, char **argv)
{
	FILE	*file = 0;
	int		check = 0;
	int		x = 0;
	int		y = 0;

	if (argc != 2)
		return (ft_puterror("Error: argument\n", 0));
	if (!(file = fopen(argv[1], "r")))
		return (ft_puterror("Error: Operation file corrupted\n", 0));
	if (fscanf(file, "%d %d %c", &g_b.width, &g_b.height, &g_b.c) != 3)
		return (ft_puterror("Error: Operation file corrupted\n", 0));
	if (!(0 < g_b.width && g_b.width <= 300 && 0 < g_b.height && g_b.height <= 300 ))
		return (ft_puterror("Error: Operation file corrupted\n", 0));

	g_b.matrix = malloc(g_b.width * g_b.height);
	memset(g_b.matrix, g_b.c, (g_b.width * g_b.height));
	check = fscanf(file, "%c %f %f %f %f %c\n", &g_r.type, &g_r.start_x, &g_r.start_y, &g_r.width, &g_r.height, &g_r.color);

	while (check == 6)
	{
		if (!(g_r.width > 0.00000000 && g_r.height > 0.00000000) || !(g_r.type == 'R' || g_r.type == 'r'))
			return (ft_puterror("Error: Operation file corrupted\n", 1));

		y = 0;
		while (y < g_b.height)
		{
			x = 0;
			while (x < g_b.width)
			{
				if (g_r.type == 'r')
				{
					if ((float)x - g_r.start_x < 1.0000000 || (g_r.start_x + g_r.width) - (float)x < 1.0000000 ||
						(float)y - g_r.start_y < 1.0000000 || (g_r.start_y + g_r.height) - (float)y < 1.0000000)
					{
						if ((float)x >= g_r.start_x && (float)x <= g_r.start_x + g_r.width && (float)y >= g_r.start_y && (float)y <= g_r.start_y + g_r.height)
							g_b.matrix[y * g_b.width + x] = g_r.color;
					}
				}
				else if (g_r.type == 'R')
				{
					if ((float)x >= g_r.start_x && (float)x <= g_r.start_x + g_r.width && (float)y >= g_r.start_y && (float)y <= g_r.start_y + g_r.height)
						g_b.matrix[y * g_b.width + x] = g_r.color;
				}
				x++;
			}
			y++;
		}

		check = fscanf(file, "%c %f %f %f %f %c\n", &g_r.type, &g_r.start_x, &g_r.start_y, &g_r.width, &g_r.height, &g_r.color);
	}
	if (check != -1)
		return (ft_puterror("Error: Operation file corrupted\n", 1));

	y = 0;
	while (y < g_b.height)
	{
		write(1, g_b.matrix + y * g_b.width, g_b.width);
		write(1, "\n", 1);
		y++;
	}

	free(g_b.matrix);
	fclose(file);
}
