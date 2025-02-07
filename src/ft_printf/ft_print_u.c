/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:26:25 by mugenan           #+#    #+#             */
/*   Updated: 2024/11/26 18:04:43 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_print_u(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}
