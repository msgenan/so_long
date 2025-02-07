/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:14:54 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/04 20:33:53 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void all_map_checks(t_content *x)
{
	map_control(x);
	read_map(x);
	check_map(x);
	check_char(x);
	flood_fill(x, x->playerx, x->playery);
	flood_check(x);
}
int main(int ac, char *av[])
{
	if (ac != 2)
		return(0);

	t_content *x;
	x = malloc(sizeof(t_content));
	x->path = av[1];
	x->random = -1;
	all_map_checks(x);
	

	int i = -1;
	while (++i < x->vertical)
		printf("%s", x->map[i]);
	printf("\n");
	i = -1;
	while (++i < x->vertical)
		printf("%s", x->mapx[i]);
}