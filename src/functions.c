/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:06:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/12 21:17:11 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(char *error)
{
    perror(error);
    exit(0);
}
int cleaner(t_content *x)
{
	free(x->map);
	free(x->mapx);
	free(x->a);
	free(x);
	exit(0);
	return(0);
}
int	length(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
void parser(t_content *x)
{
	x->a->move = 0;
	x->counter = 0;
	textures_to_variable(x);
	parse_img(x);
	mlx_key_hook(x->a->window, key_press, x);
	mlx_hook(x->a->window, 17, 0, cleaner, x);
	mlx_loop(x->a->mlx);
}