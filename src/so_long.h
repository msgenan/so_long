/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:14:29 by mugenan           #+#    #+#             */
/*   Updated: 2025/02/17 19:08:32 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_mlx
{
	int		x;
	int		y;
	int		move;
	void	*mlx;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*player;
	void	*window;
	void	*collect;

}	t_mlx;

typedef struct s_content
{
	t_mlx	*a;
	int		c;
	int		e;
	int		p;
	char	*gnl;
	char	*path;
	char	**map;
	char	**mapx;
	int		random;
	int		counter;
	int		playerx;
	int		playery;
	int		vertical;
	int		horizontal;
	int		newplayerx;
	int		newplayery;

}	t_content;

int		ft_cleaner(t_content *x);
int		length(const char *str);
int		key_press(int keycode, t_content *x);
void	error(char *error);
void	ft_free_map(t_content *x);
void	ft_image_destroy(t_content *x);
void	read_map(t_content *x);
void	parse_img(t_content *x);
void	which_key(t_content *x);
void	check_map(t_content *x);
void	map_parser(t_content *x);
void	check_char(t_content *x);
void	map_control(t_content *x);
void	flood_check(t_content *x);
void	all_map_checks(t_content *x);
void	textures_to_variable(t_content *x);
void	flood_fill(t_content *x, int playerx, int playery);
void	key_press_update(char move, int nby, int nbx, t_content *x);

#endif