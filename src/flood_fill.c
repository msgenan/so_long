/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:02:18 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/25 17:37:02 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_content *x, int playerx, int playery)
{
	if (playery >= x->vertical || playerx >= x->horizontal)
		return ;
	if (x->mapx[playery][playerx] == '1' || x->mapx[playery][playerx] == 'x'
	|| x->mapx[playery][playerx] == 'E')
		return ;
	x->mapx[playery][playerx] = 'x';
	flood_fill(x, playerx + 1, playery);
	flood_fill(x, playerx - 1, playery);
	flood_fill(x, playerx, playery + 1);
	flood_fill(x, playerx, playery - 1);
}

void	flood_check(t_content *x)
{
	int	i;

	i = -1;
	while (++x->random < x->vertical)
	{
		i = -1;
		while (++i < x->horizontal)
		{
			if (x->mapx[x->random][i] == 'E')
				exit_control(x, i);
			if (x->mapx[x->random][i] != '1' && x->mapx[x->random][i] != 'x'
			&& x->mapx[x->random][i] != 'E')
				return (ft_free_map(x), free(x),
					error ("There is an unreachable area in the map!"));
		}
	}
}

void	exit_control(t_content *x, int i)
{
	int	flag;

	flag = 0;
	if (x->mapx[x->random][i + 1] == '1')
		flag++;
	if (x->mapx[x->random][i - 1] == '1')
		flag++;
	if (x->mapx[x->random + 1][i] == '1')
		flag++;
	if (x->mapx[x->random - 1][i] == '1')
		flag++;
	if (flag == 4)
		return (ft_free_map(x), free(x),
			error ("The exit is surrounded by walls!"));
}
