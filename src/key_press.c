/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:22:20 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/17 21:06:53 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_content *x)
{
	if (keycode == 65307)
		ft_cleaner(x);
	else if (keycode == 119 || keycode == 65362)
		key_press_update('W', -1, 0, x);
	else if (keycode == 97 || keycode == 65361)
		key_press_update('A', 0, -1, x);
	else if (keycode == 115 || keycode == 65364)
		key_press_update('S', 1, 0, x);
	else if (keycode == 100 || keycode == 65363)
		key_press_update('D', 0, 1, x);
	return (0);
}

void	key_press_update(char move, int nby, int nbx, t_content *x)
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

void	which_key(t_content *x)
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
			ft_cleaner(x);
		}
		return ;
	}
	x->map[x->playery][x->playerx] = '0';
	x->map[x->newplayery][x->newplayerx] = 'P';
	x->playery = x->newplayery;
	x->playerx = x->newplayerx;
	parse_img(x);
}
