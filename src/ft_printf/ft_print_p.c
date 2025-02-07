/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:54:41 by mugenan           #+#    #+#             */
/*   Updated: 2024/12/13 19:54:10 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long nb, char *base, int flag)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	if (flag == 1)
		len += ft_putstr("0x");
	if (nb >= 16)
		len += ft_print_p(nb / 16, base, 0);
	len += write(1, &base[nb % 16], 1);
	return (len);
}
