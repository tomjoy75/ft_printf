/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:39:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/20 17:55:53 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list ap)
{
	unsigned int	nb;
	int	i;
//	int	sign;
	int	size;
	char	tab[11];

	nb = va_arg(ap, int);
//	sign = 0;
	i = 0;
/*	if (nb < 0)
	{
		ft_putchar('-');
		sign++;
		nb *= -1;
	}*/
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (nb > 0)
	{
		tab[i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	size = i;
	while (--i >= 0)
		 ft_putchar(tab[i]);
	return (size);
}


		
