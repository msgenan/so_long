/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 02:08:16 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/04 20:33:46 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_control(t_content *x)
{
	char *str;
	int i;
	int j;
	
	i = 0;
	j = 0;
	str = "reb.";
	
	while(x->path[i])
		i++;
	while((x->path[--i] == str[j]) && str[j])
		j++;
	if(j != 4)
		return(error("Map girdisi hatalı!"));
}
void read_map(t_content *x)
{
	int i;
	int fd;

	i = 0;
	x->vertical = 0;
	fd = open(x->path, O_RDWR);
	while(get_next_line(fd))
		x->vertical++;
	x->map = malloc(sizeof(char *) * x->vertical);
	x->mapx = malloc(sizeof(char *) * x->vertical);
	close(fd);
	fd = open(x->path, O_RDWR);
	while(i < x->vertical)
    	x->map[i++] = get_next_line(fd);
	close(fd);
	fd = open(x->path, O_RDWR);
	i = 0;
	while(i < x->vertical)
    	x->mapx[i++] = get_next_line(fd);
	close(fd);
	if (!(x->map[i - 1]) || !(x->mapx[i - 1]))
		error("Gnl fonksiyonunda bir problem oluştu!");
	x->horizontal = length(x->map[0]);
}
void check_map(t_content *x)
{
	while(++x->random < x->vertical)
	{
		if (length(x->map[x->random]) != x->horizontal)
			error("Girdiğiniz mapin satırları hatalı!");
		if (x->map[x->random][0] != '1' || x->map[x->random][x->horizontal - 1] != '1')
			error("Map duvarlarında problem var!");
	}
	while(++x->random < x->vertical + x->horizontal)
	{
		if (x->map[0][x->random - x->vertical] != '1' 
		|| x->map[x->vertical - 1][x->random - x->vertical] != '1')
			error("Map duvarlarında problem var!");
	}
	x->random = -1;
}
void check_char(t_content *x)
{
	int i;

	i = -1;
	while(++x->random < x->vertical)
	{
		i = -1;
		while(++i < x->horizontal)
		{
			if (x->map[x->random][i] == 'C')
				x->c++;
			else if (x->map[x->random][i] == 'E')
				assignment_location(x, 'E', i);
			else if (x->map[x->random][i] == 'P')
				assignment_location(x, 'P', i);
			else if (x->map[x->random][i] != '1' && x->map[x->random][i] != '0')
				error("Mapte bilinmeyen harf kullanımı mevcut!");
		}
	}
	if (x->e != 1 || x->p != 1 || x->c < 1)
		error("Verdiğiniz karakterler kurallara uymuyor");
	x->random = -1;
}
void	assignment_location(t_content *x, char c, int i)
{
	if (c == 'P')
	{
		x->p++;
		x->playery = x->random;
		x->playerx = i;
	}
	if (c == 'E')
	{
		x->e++;
		x->exity = x->random;
		x->exitx = i;
	}	
}
