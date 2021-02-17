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

typedef struct	s_c
{
	char	type;
	float	center_x;
	float	center_y;
	float	r;
	char	color;
}				t_c;

t_b		g_b;
t_c		g_c;

int		ft_puterror(char *s, int fr)
{
	int		i = 0;

	while (s[i]) i++;
	write(1, s, i);

	if (fr) free(g_b.matrix);

	return (1);
}

int		main(int argc, char **argv)
{
	FILE	*file = 0;
	float	distance = 0;
	int		check = 0;
	int		x = 0;
	int		y = 0;

	if (argc != 2)
		return (ft_puterror("Error: argument\n", 0));

	if (!(file = fopen(argv[1], "r")))
		return (ft_puterror("Error: Operation file corrupted\n", 0));

	if (fscanf(file, "%d %d %c\n", &g_b.width, &g_b.height, &g_b.c) != 3)
		return (ft_puterror("Error: Operation file corrupted\n", 0));

	if (!(0 <= g_b.width && g_b.width <= 300 && 0 <g_b.height && g_b.height <= 300))
		return (ft_puterror("Error: Operation file corrupted\n", 0));

	g_b.matrix = malloc(g_b.width * g_b.height);
	memset(g_b.matrix, g_b.c, (g_b.width * g_b.height));

	check = fscanf(file, "%c %f %f %f %c\n", &g_c.type, &g_c.center_x, &g_c.center_y, &g_c.r, &g_c.color);
	while(check == 5)
	{
		if (!(g_c.r > 0) || !(g_c.type == 'c' || g_c.type == 'C'))
			return (ft_puterror("--Error: Operation file corrupted\n", 1));

		y = 0;
		while (y < g_b.height)
		{
			x = 0;
			while (x < g_b.width)
			{
				distance = sqrtf(powf(x - g_c.center_x, 2.) + powf(y - g_c.center_y, 2.));
				if (distance <= g_c.r)
				{
					if (g_c.type == 'c')
					{
						if (g_c.r - distance < 1.0000000)
							g_b.matrix[y * g_b.width + x] = g_c.color;
					}
					else if (g_c.type == 'C')
						g_b.matrix[y * g_b.width + x] = g_c.color;
				}
				x++;
			}
			y++;
		}
		check = fscanf(file, "%c %f %f %f %c\n", &g_c.type, &g_c.center_x, &g_c.center_y, &g_c.r, &g_c.color);
	}

	if (check == -1)
	{
		y = 0;
		while (y < g_b.height)
		{
			write(1, g_b.matrix + y * g_b.width, g_b.width);
			write(1, "\n", 1);
			y++;
		}
	}
	else
		return (ft_puterror("Error: Operation file corrupted\n", 1));

	free(g_b.matrix);
	fclose(file);
}
