/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:06:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/19 03:25:48 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *error)
{
	perror(error);
	exit(0);
}

int	ft_cleaner(t_content *x)
{
	ft_free_map(x);
	ft_image_destroy(x);
	free(x->a->mlx);
	free(x->a);
	free(x);
	exit(0);
	return (0);
}

void	ft_image_destroy(t_content *x)
{
	mlx_clear_window(x->a->mlx, x->a->window);
	mlx_destroy_window(x->a->mlx, x->a->window);
	mlx_destroy_image(x->a->mlx, x->a->collect);
	mlx_destroy_image(x->a->mlx, x->a->player);
	mlx_destroy_image(x->a->mlx, x->a->wall);
	mlx_destroy_image(x->a->mlx, x->a->exit);
	mlx_destroy_image(x->a->mlx, x->a->floor);
	mlx_destroy_display(x->a->mlx);
}

void	ft_free_map(t_content *x)
{
	int	i;

	i = 0;
	while (x->vertical > i)
	{
		free(x->map[i]);
		free(x->mapx[i]);
		i++;
	}
	free(x->map);
	free(x->mapx);
}

int	length(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
