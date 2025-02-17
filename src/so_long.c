/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:14:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/17 21:34:03 by mugenan          ###   ########.fr       */
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
		return(free(x), error("An error occurred while allocating memory for t_content!"), 0);
	x->path = av[1];
	all_map_checks(x);
	x->a = malloc(sizeof(t_mlx));
	if (!x->a)
		return(free(x), error("An error occurred while allocating memory for t_mlx!"), 0);
	map_parser(x);
}
