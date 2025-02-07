#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "./gnl/get_next_line.h"
#include "./mlx/mlx.h"
#include "./mlx/mlx_int.h"


typedef struct s_content
{
	char **map;
	char **mapx;
	char *path;
	int vertical;
	int horizontal;
	int random;
	int playerx;
	int playery;
	int exitx;
	int exity;
	int c;
	int e;
	int p;

}	t_content;

void map_control(t_content *x);
void check_char(t_content *x);
void check_map(t_content *x);
void read_map(t_content *x);
int	length(const char *str);
void error(char *error);
void flood_check(t_content *x);
void all_map_checks(t_content *x);
void	flood_fill(t_content *x, int playerx, int playery);
void	assignment_location(t_content *x, char c, int i);


#endif