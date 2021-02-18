#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_background
{
	int		width;
	int		height;
	char	bc;
}				t_background;

typedef struct	s_rectangle
{
	char	type;
	float	start_x;
	float	start_y;
	float	width;
	float	height;
	char	color;
}				t_rectangle;

t_background	b;
t_rectangle		r;
char*			image;

int		ft_puterror(char *s, int fr)
{
	int		i = 0;

	while (s && s[i]) i++;
	write(1, s, i);

	if (fr) free(image);
	return (1);
}

int		main(int argc, char **argv)
{
	FILE	*file = 0;
	int		x = 0;
	int		y = 0;
	int		size = 0;
	float	check = 1.0000000;

	if (argc != 2)
		return (ft_puterror("Error: argument\n", 0));

	if (!(file = fopen(argv[1], "r")))
		return (ft_puterror("Error: Operation file corrupted\n", 0));

	if (fscanf(file, "%d %d %c\n", &b.width, &b.height, &b.bc) != 3)
		return (ft_puterror("Error: Operation file corrupted\n", 0));

	if (!(0 < b.width && b.width <= 300 && 0 < b.height && b.height <= 300))
		return (ft_puterror("Error: Operation file corrupted\n", 0));

	image = malloc(b.width * b.height);
	memset(image, b.bc, (b.width * b.height));

	size = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.start_x, &r.start_y, &r.width, &r.height, &r.color);
	while (size == 6)
	{
		if (!(r.width > 0 && r.height > 0) || !(r.type == 'r' || r.type == 'R'))
			return (ft_puterror("Error: Operation file corrupted\n", 1));

		y = 0;
		while (y < b.height)
		{
			x = 0;
			while (x < b.width)
			{
				if (r.type == 'r')
				{
					if (x - r.start_x < check || (r.start_x + r.width) - x < check ||
						y - r.start_y < check || (r.start_y + r.height) - y < check)
					{
						if (r.start_x <= x && x <= (r.start_x + r.width) &&
							r.start_y <= y && y <= (r.start_y + r.height))
							image[y * b.width + x] = r.color;
					}
				}
				else if (r.type == 'R')
				{
					if (r.start_x <= x && x <= (r.start_x + r.width) &&
						r.start_y <= y && y <= (r.start_y + r.height))
						image[y * b.width + x] = r.color;
				}
				x++;
			}
			y++;
		}
		size = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.start_x, &r.start_y, &r.width, &r.height, &r.color);
	}

	if (size == -1)
	{
		y = 0;
		while (y < b.height)
		{
			write(1, image + y * b.width , b.width);
			write(1, "\n", 1);
			y++;
		}
	}
	else
		return (ft_puterror("Error: Operation file corrupted\n", 1));

	free(image);
	fclose(file);
}
