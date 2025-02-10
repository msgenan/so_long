/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:14:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/10 14:30:23 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char *av[])
{
	if (ac != 2)
		return(0);
	t_content *x;
	x = malloc(sizeof(t_content));
	if (!x)
		error("t_content için bellek ayırılmasında bir hata yaşandı");
	x->a = malloc(sizeof(t_mlx));
	if (!x->a)
		error("t_mlx için bellek ayırılmasında bir hata yaşandı");
	x->path = av[1];
	all_map_checks(x);
	x->a->mlx = mlx_init();
	if (!x->a->mlx)
		error("mlx fonksiyonu başlatılamadı!");
	x->a->window = mlx_new_window(x->a->mlx, x->a->x, x->a->y, "so_long");
	if (!x->a->window)
		error("mlx pencere oluşturmada bir hata yaşadı!");
	x->a->move = 0;
	x->counter = 0;
	textures_to_variable(x);
	parse_img(x);
	mlx_key_hook(x->a->window, key_press, x);
	mlx_loop(x->a->mlx);
}
