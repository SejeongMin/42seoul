#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_board
{
	int width;
	int height;
	char background;
}				t_board;

typedef struct	s_rectangle
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char c;
}				t_rectangle;

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

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	get_board(FILE *file, t_board *board)
{
	int	scanf_ret;

	if ((scanf_ret = fscanf(file, "%d %d %c\n", &board->width, &board->height, &board->background)) != 3)
		return (1);
	if (board->width <= 0 || board->width > 300 || board->height <= 0 || board->height > 300)
		return (1);
	if (scanf_ret == -1)
		return (1);
	return (0);
}

int	is_in_rectangle(float x, float y, t_rectangle *rectangle)
{
	if (((x < rectangle->x || (rectangle->x + rectangle->width < x))
		|| (y < rectangle->y)) || (rectangle->y + rectangle->height < y))
		return (0);
	if (((x - rectangle->x < 1.0) || ((rectangle->x + rectangle->width) - x < 1.0)) ||
	((y - rectangle->y < 1.0 || ((rectangle->y + rectangle->height) - y < 1.0))))
		return (2);
	return (1);
}

void	fill_rectangle(char **buffer, t_rectangle *rectangle, t_board *board)
{
	int i;
	int j;
	int ret;

	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			ret = is_in_rectangle(j, i, rectangle);
			if ((rectangle->type == 'r' && ret == 2)
				|| (rectangle->type == 'R' && ret))
				(*buffer)[(i * board->width) + j] = rectangle->c;
			j++;
		}
		i++;
	}
}

void drawing(char *buffer, t_board *board)
{
	int i = 0;
	while (i < board->height)
	{
		write(1, &buffer[i * board->width], board->width);
		write(1, "\n", 1);
		i++;
	}
}

int	fill_bg(FILE *fp, t_board *board)
{
	char *buffer;
	buffer = (char*)malloc(board->width * board->height);
	int i = 0;
	while (i < board->height * board->width)
	{
		buffer[i] = board->background;
		i++;
	}
	int ret = 0;
	t_rectangle s;
	while ((ret = fscanf(fp, "%c %f %f %f %f %c\n", &s.type, &s.x, &s.y, &s.width, &s.height, &s.c)) == 6)
	{
		fill_rectangle(&buffer, &s, board);
	}
	drawing(buffer, board);
	free(buffer);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (print_error("Error: argument\n"));
	t_board board;
	FILE	*fp;
	if (!(fp = fopen(av[1], "r")))
		return (print_error("Error: Operation file corrupted\n"));
	if (get_board(fp, &board))
	{
		fclose(fp);
		write(1, "Error: Operation file corrupted\n", 33);
	}
	fill_bg(fp, &board);
	fclose(fp);
	return (0);
}
