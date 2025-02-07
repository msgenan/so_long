/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:14:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/07 20:38:59 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void all_map_checks(t_content *x, mlx *a)
{
	x->random = -1;
	map_control(x);
	read_map(x);
	check_map(x);
	check_char(x);
	flood_fill(x, x->playerx, x->playery);
	flood_check(x);
	a->x = x->horizontal * 64;
	a->y = x->vertical * 64;
}


int main(int ac, char *av[])
{
	if (ac != 2)
		return(0);

	t_content *x;
	x = malloc(sizeof(t_content));
	x->path = av[1];
	mlx *a;
	a = malloc(sizeof(mlx));
	a->mlx = mlx_init();
	if (!a->mlx)
		error("mlx fonksiyonu başlatılamadı");
	all_map_checks(x, a);
	a->window = mlx_new_window(a->mlx, a->x, a->y, "so_long");
	// window oluşamama erroru yaz
	
	int i = -1;
	while (++i < x->vertical)
		printf("%s", x->map[i]);
	printf("\n");
}
