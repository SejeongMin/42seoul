#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_board
{
	int		width;
	int		height;
	char	bg;
}				t_board;

typedef struct	s_circle
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	c;
}				t_circle;

int	my_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	print_error(char *str)
{
	write(STDOUT_FILENO, str, my_strlen(str) + 1);
	return (1);
}

int	fill_board(FILE *fp, char **buffer, t_board *board)
{
	int		ret;

	if ((ret = fscanf(fp, "%d %d %c\n", &board->width, &board->height, &board->bg)) != 3)
		return (print_error("Error: Operation file corrupted\n"));
	*buffer = (char *)malloc(board->width * board->height);
	for (int i = 0; i < board->width * board->height; i++){
		(*buffer)[i] = board->bg;
	}
	return (0);
}

int	is_in_circle(t_circle circle, int x, int y)
{
	float	distance, dx, dy;

	dx = (circle.x > x) ? circle.x - x : x - circle.x;
	dy = (circle.y > y) ? circle.y - y : y - circle.y;
	distance = sqrtf(powf(dx, 2.0) + powf(dy, 2.0));
	if (distance <= circle.radius && circle.radius - distance < 1.0)
		return (2);
	if (distance <= circle.radius)
		return (1);
	return (0);
}

void fill_circles(FILE *fp, char **buffer, t_board *board)
{
	t_circle	circle;
	int			ret, i, j;

	while ((ret = fscanf(fp, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.c)) == 5)
	{
		i = 0;
		while (i < board->height)
		{
			j = 0;
			while (j < board->width)
			{
				if (circle.type == 'c' && (is_in_circle(circle, j, i) == 2)
					|| (circle.type == 'C' && is_in_circle(circle,j, i)))
				{
					(*buffer)[(board->width) * i + j] = circle.c;
				}
				j++;
			}
			i++;
		}
	}	
}

void	drawing(char *buffer, t_board board)
{
	int i = 0;

	while (i < board.height)
	{
		write(STDOUT_FILENO, &buffer[board.width * i], board.width);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*buffer;
	t_board	board;

	if (ac != 2)
		return (print_error("Error: argument\n"));
	FILE	*fp;
	if (!(fp = fopen(av[1], "r")))
		return (print_error("Error: Operation file corrupted\n"));
	if (fill_board(fp, &buffer, &board))
		return (print_error("Error: Operation file corrupted\n"));
	fill_circles(fp, &buffer, &board);
	drawing(buffer, board);
	fclose(fp);
	free(buffer);
	return (0);
}
