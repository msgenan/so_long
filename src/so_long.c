/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:14:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/28 18:28:28 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_content	*x;

	if (ac != 2)
		return (0);
	x = malloc(sizeof(t_content));
	if (!x)
		error("Memory allocation for t_content failed!");
	x->path = av[1];
	all_map_checks(x);
	x->a = malloc(sizeof(t_mlx));
	if (!x->a)
		return (free(x), error("Memory allocation for t_mlx failed!"), 0);
	map_parser(x);
}
