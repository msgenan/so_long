/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 02:08:16 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/19 03:24:06 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_control(t_content *x)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = "reb.";
	while (x->path[i])
		i++;
	while ((x->path[--i] == str[j]) && str[j])
		j++;
	if (j != 4)
		return (free(x), error ("Map input is incorrect!"));
}

void	read_map(t_content *x)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(x->path, O_RDWR);
	x->gnl = get_next_line(fd);
	while (x->gnl)
	{
		free(x->gnl);
		x->vertical++;
		x->gnl = get_next_line(fd);
	}
	x->map = malloc(sizeof(char *) * x->vertical);
	x->mapx = malloc(sizeof(char *) * x->vertical);
	close (fd);
	fd = open(x->path, O_RDWR);
	while (i < x->vertical)
		x->map[i++] = get_next_line(fd);
	close (fd);
	fd = open(x->path, O_RDWR);
	i = 0;
	while (i < x->vertical)
		x->mapx[i++] = get_next_line(fd);
	close(fd);
}

void	check_map(t_content *x)
{
	x->horizontal = length(x->map[0]);
	x->random = -1;
	if ((x->map[x->vertical - 1][x->horizontal]) == '\n')
		return (ft_free_map(x), free(x),
			error("The last row of the map contains only a newline!"));
	while (++x->random < x->vertical)
	{
		if (length (x->map[x->random]) != x->horizontal)
			return (ft_free_map(x), free(x), error("Map lines are incorrect!"));
		if (x->map[x->random][0] != '1' ||
			x->map[x->random][x->horizontal - 1] != '1')
			return (ft_free_map(x), free(x), error("Map walls are incorrect!"));
	}
	while (++x->random < x->vertical + x->horizontal)
	{
		if (x->map[0][x->random - x->vertical] != '1'
		|| x->map[x->vertical - 1][x->random - x->vertical] != '1')
			return (ft_free_map(x), free(x), error("Map walls are incorrect!"));
	}
	x->random = -1;
}

void	check_char(t_content *x)
{
	int	i;

	while (++x->random < x->vertical)
	{
		i = -1;
		while (++i < x->horizontal)
		{
			if (x->map[x->random][i] == 'C')
				x->c++;
			else if (x->map[x->random][i] == 'E')
				x->e++;
			else if (x->map[x->random][i] == 'P')
			{
				x->p++;
				x->playery = x->random;
				x->playerx = i;
			}
			else if (x->map[x->random][i] != '1' && x->map[x->random][i] != '0')
				return (ft_free_map(x), free(x),
					error("Map variables are incorrect!"));
		}
	}
	x->random = -1;
}

void	all_map_checks(t_content *x)
{
	x->random = -1;
	x->c = 0;
	x->e = 0;
	x->p = 0;
	x->vertical = 0;
	map_control(x);
	read_map(x);
	if (x->vertical == 0)
		return (ft_free_map(x), free(x), error("Invalid map dimensions!"));
	if (!(x->map) || !(x->mapx))
		return (ft_free_map(x), free(x),
			error ("An error occurred while reading the map!"));
	check_map(x);
	check_char(x);
	if (x->e != 1 || x->p != 1 || x->c < 1)
		return (ft_free_map(x), free(x),
			error("Numbers of the map variables are incorrect!"));
	flood_fill(x, x->playerx, x->playery);
	flood_check(x);
}
