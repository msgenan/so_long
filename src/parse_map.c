/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:38:23 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/07 21:26:37 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void textures_to_variable(mlx *a)
{
	a->collect = mlx_xpm_file_to_image(a->mlx, "./textures/collect.xpm", 64, 64);
	a->exit = mlx_xpm_file_to_image(a->mlx, "./textures/exit.xpm", 64, 64);
	a->floor = mlx_xpm_file_to_image(a->mlx, "./textures/floor.xpm", 64, 64);
	a->player = mlx_xpm_file_to_image(a->mlx, "./textures/player.xpm", 64, 64);
	a->wall = mlx_xpm_file_to_image(a->mlx, "./textures/wall.xpm", 64, 64);
}
void parse_img(t_content *x, mlx *a)
{
	int i;
	while(x->random < a->y)
	{
		i = 0;
		while(i < a->x)
		{
			if (x->map[x->random][i] == '1')
				mlx_put_image_to_window(a->mlx, a->mlx, a->wall, x->random, i);
			else if (x->map[x->random][i] == '0')
				mlx_put_image_to_window(a->mlx, a->mlx, a->floor, x->random, i);
			else if (x->map[x->random][i] == 'E')
				mlx_put_image_to_window(a->mlx, a->mlx, a->exit, x->random, i);
			else if (x->map[x->random][i] == 'P')
				mlx_put_image_to_window(a->mlx, a->mlx, a->player, x->random, i);
			else if (x->map[x->random][i] == 'C')
				mlx_put_image_to_window(a->mlx, a->mlx, a->collect, x->random, i);
			i += 64;
		}
		x->random += 64;
	}
}
