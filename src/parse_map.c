/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:38:23 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/12 20:42:21 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void textures_to_variable(t_content *x)
{
	int i = 64;
	int j = 64;

	x->a->collect = mlx_xpm_file_to_image(x->a->mlx, "./src/textures/collect.xpm", &i, &j);
	if (!x->a->collect)
		printf("Error: collect.xpm yüklenemedi!\n");
	x->a->exit = mlx_xpm_file_to_image(x->a->mlx, "./src/textures/exit.xpm", &i, &j);
	if (!x->a->exit)
		printf("Error: exit.xpm yüklenemedi!\n");
	x->a->floor = mlx_xpm_file_to_image(x->a->mlx, "./src/textures/floor.xpm", &i, &j);
	if (!x->a->floor)
		printf("Error: floor.xpm yüklenemedi!\n");
	x->a->player = mlx_xpm_file_to_image(x->a->mlx, "./src/textures/player.xpm", &i, &j);
	if (!x->a->player)
		printf("Error: player.xpm yüklenemedi!\n");
	x->a->wall = mlx_xpm_file_to_image(x->a->mlx, "./src/textures/wall.xpm", &i, &j);
	if (!x->a->wall)
		printf("Error: wall.xpm yüklenemedi!\n");
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
			if (x->map[i][j] == '1')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->wall, j * 64, i * 64);
			else if (x->map[i][j] == '0')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->floor, j * 64, i * 64);
			else if (x->map[i][j] == 'E')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->exit, j * 64, i * 64);
			else if (x->map[i][j] == 'C')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->collect, j * 64, i * 64);
			else if (x->map[i][j] == 'P')
				mlx_put_image_to_window(x->a->mlx, x->a->window, x->a->player, j * 64, i * 64);

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
		key_press_update('W', -1, 0, x);
	else if (keycode == 97 || keycode == 65361)
		key_press_update('A', 0, -1, x);
	else if (keycode == 115 || keycode == 65364)
		key_press_update('S', 1, 0, x);
	else if (keycode == 100 || keycode == 65363)
		key_press_update('D', 0, 1, x);
	return(0);
}
void key_press_update(char move, int nby, int nbx, t_content *x)
{
	if (move == 'W' && x->map[x->playery + nby][x->playerx + nbx] != '1')
	{
		x->newplayery = x->playery + nby;
		x->newplayerx = x->playerx + nbx;
		which_key(x);
	}
	else if (move == 'A' && x->map[x->playery + nby][x->playerx + nbx] != '1')
	{
		x->newplayery = x->playery + nby;
		x->newplayerx = x->playerx + nbx;
		which_key(x);
	}
	else if (move == 'S' && x->map[x->playery + nby][x->playerx + nbx] != '1')
	{
		x->newplayery = x->playery + nby;
		x->newplayerx = x->playerx + nbx;
		which_key(x);
	}
	else if (move == 'D' && x->map[x->playery + nby][x->playerx + nbx] != '1')
	{
		x->newplayery = x->playery + nby;
		x->newplayerx = x->playerx + nbx;
		which_key(x);
	}
}
void which_key(t_content *x)
{
	x->a->move++;
	if (x->map[x->newplayery][x->newplayerx] == 'C')
		x->counter++;
	else if (x->map[x->newplayery][x->newplayerx] == 'E')
	{
		if (x->counter == x->c)
		{
			printf("oyunu bitirdiniz, tebrikler!\n");
			printf("Hamle sayısı: %d\n", x->a->move);
			exit(0);
		}
		return;
	}
	x->map[x->playery][x->playerx] = '0';
	x->map[x->newplayery][x->newplayerx] = 'P';
	x->playery = x->newplayery;
	x->playerx = x->newplayerx;
	parse_img(x);
}