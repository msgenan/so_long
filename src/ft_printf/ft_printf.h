/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:48:24 by mugenan           #+#    #+#             */
/*   Updated: 2024/11/26 18:06:34 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_print_id(int nb);
int	ft_print_u(unsigned int nb);
int	ft_check(char c, va_list args);
int	ft_printf(const char *str, ...);
int	ft_print_x(unsigned int nb, char *base);
int	ft_print_p(unsigned long nb, char *base, int flag);

#endif