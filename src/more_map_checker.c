/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_map_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:02:18 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/10 14:21:48 by mugenan          ###   ########.fr       */
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

void flood_check(t_content *x)
{
	int i;

	i = -1;
	while(++x->random < x->vertical)
	{
		i = -1;
		while(++i < x->horizontal)
		{
			if (x->mapx[x->random][i] != '1' && x->mapx[x->random][i] != 'x'
			&& x->mapx[x->random][i] != 'E')
				error("Mapte ulaşılamayan alan tespit edildi");
		}
	}
}
void all_map_checks(t_content *x)
{
	x->random = -1;
	map_control(x);
	read_map(x);
	check_map(x);
	check_char(x);
	flood_fill(x, x->playerx, x->playery);
	flood_check(x);
}
