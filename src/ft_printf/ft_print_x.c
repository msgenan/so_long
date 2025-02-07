/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:16:58 by mugenan           #+#    #+#             */
/*   Updated: 2024/11/26 18:05:40 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_print_x(nb / 16, base);
	len += write(1, &base[nb % 16], 1);
	return (len);
}
