/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:38:23 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/10 14:55:00 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void textures_to_variable(t_content *x)
{
	int i;
	int j;

	i = 64;
	j = 64;
	x->a->collect = mlx_xpm_file_to_image(x->a->mlx, "./textures/collect.xpm", &i, &j);
	x->a->exit = mlx_xpm_file_to_image(x->a->mlx, "./textures/exit.xpm", &i, &j);
	x->a->floor = mlx_xpm_file_to_image(x->a->mlx, "./textures/floor.xpm", &i, &j);
	x->a->player = mlx_xpm_file_to_image(x->a->mlx, "./textures/player.xpm", &i, &j);
	x->a->wall = mlx_xpm_file_to_image(x->a->mlx, "./textures/wall.xpm", &i, &j);
}
void parse_img(t_content *x)
{
	int	i;
	int	j;

	i = 0;
	while (i < x->vertical)
	{
		j = 0;
		while (j < x->horizontal)
		{
			if (x->map[i][j] != '1')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->wall, i * 64, j * 64);
			if (x->map[i][j] == '1')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->wall, i * 64, j * 64);
			else if (x->map[i][j] == 'E')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->exit, i * 64, j * 64);
			else if (x->map[i][j] == 'C')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->collect, i * 64, j * 64);
			else if (x->map[i][j] == 'P')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->player, i * 64, j * 64);
			j++;
		}
		i++;
	}
}
int key_press(int keycode, t_content *x)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119 || keycode == 65362)
		key_press_update('W', -1, 0, 0, x);
	else if (keycode == 97 || keycode == 65361)
		key_press_update('A', -1, 0, 0, x);
	else if (keycode == 115 || keycode == 65364)
		key_press_update('S', 0, 1, 0, x);
	else if (keycode == 100 || keycode == 65363)
		key_press_update('D', 0, 1, 0, x);
	return(0);
}
void key_press_update(char move, int nby, int nbx, int flag, t_content *x)
{
	if (move == 'W' && x->map[x->playery + nby][x->playerx + nbx] != '1')
		flag = 1;
	else if (move == 'A' && x->map[x->playery + nby][x->playerx + nbx] != '1')
		flag = 1;
	else if (move == 'S' && x->map[x->playery + nby][x->playerx + nbx] != '1')
		flag = 1;
	else if (move == 'D' && x->map[x->playery + nby][x->playerx + nbx] != '1')
		flag = 1;
	if (flag == 1)
		which_key(nby, nbx, x);	
		
}
void which_key(int nby, int nbx, t_content *x)
{
	if (x->map[x->playery + nby][x->playerx + nbx] == 'C')
		x->counter++;
	else if (x->map[x->playery + nby][x->playerx + nbx] == 'E')
	{
		if (x->counter == x->c)
		{
			printf("oyunu bitirdiniz, tebrikler!");
			exit(0);
		}
		parse_img(x);
	}
	x->map[x->playery][x->playerx] = '0';
	x->map[x->playery + nby][x->playerx + nbx] = 'P';
	parse_img(x);
}