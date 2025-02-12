/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:14:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/12 21:16:49 by mugenan          ###   ########.fr       */
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
	if (x->horizontal <= 0 || x->vertical <= 0)
    	error("Harita boyutları geçersiz!");
	x->a->window = mlx_new_window(x->a->mlx, x->horizontal * 64, x->vertical * 64, "so_long");
	if (!x->a->window)
    	error("mlx pencere oluşturmada bir hata yaşadı!");
	if (!x->a->window)
		error("mlx pencere oluşturmada bir hata yaşadı!");
	parser(x);
}
