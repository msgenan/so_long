/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:38:23 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/24 19:08:11 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parser(t_content *x)
{
	x->a->move = 0;
	x->counter = 0;
	x->a->mlx = mlx_init();
	if (!x->a->mlx)
		return (ft_free_map(x), free(x->a),
			free(x), error("Failed to initialize the mlx function!"));
	x->a->window = mlx_new_window(x->a->mlx, x->horizontal * 64,
			x->vertical * 64, "so_long");
	if (!x->a->window)
		return (ft_free_map(x), free(x->a->mlx), free(x->a),
			free(x), error("Failed to initialize the mlx_window function!"));
	x->random = -1;
	textures_to_variable(x);
	parse_img(x);
	mlx_key_hook(x->a->window, key_press, x);
	mlx_hook(x->a->window, 17, 0, ft_cleaner, x);
	mlx_loop(x->a->mlx);
}

void	textures_to_variable(t_content *x)
{
	int	i;
	int	j;

	i = 64;
	j = 64;
	x->a->collect = mlx_xpm_file_to_image(x->a->mlx,
			"./src/textures/collect.xpm", &i, &j);
	x->a->exit = mlx_xpm_file_to_image(x->a->mlx,
			"./src/textures/exit.xpm", &i, &j);
	x->a->floor = mlx_xpm_file_to_image(x->a->mlx,
			"./src/textures/floor.xpm", &i, &j);
	x->a->player = mlx_xpm_file_to_image(x->a->mlx,
			"./src/textures/player.xpm", &i, &j);
	x->a->wall = mlx_xpm_file_to_image(x->a->mlx,
			"./src/textures/wall.xpm", &i, &j);
}

void	parse_img(t_content *x)
{
	int	i;

	i = -1;
	while (++i < x->vertical)
	{
		x->random = -1;
		while (++x->random < x->horizontal)
		{
			if (x->map[i][x->random] == '1')
				mlx_put_image_to_window(x->a->mlx, x->a->window,
					x->a->wall, x->random * 64, i * 64);
			else if (x->map[i][x->random] == '0')
				mlx_put_image_to_window(x->a->mlx, x->a->window,
					x->a->floor, x->random * 64, i * 64);
			else if (x->map[i][x->random] == 'E')
				mlx_put_image_to_window(x->a->mlx, x->a->window,
					x->a->exit, x->random * 64, i * 64);
			else if (x->map[i][x->random] == 'C')
				mlx_put_image_to_window(x->a->mlx, x->a->window,
					x->a->collect, x->random * 64, i * 64);
			else if (x->map[i][x->random] == 'P')
				mlx_put_image_to_window(x->a->mlx, x->a->window,
					x->a->player, x->random * 64, i * 64);
		}
	}
}
