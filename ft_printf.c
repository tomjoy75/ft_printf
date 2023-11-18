/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:28:47 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/19 00:47:55 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NB_CONVERTER 1

void	init_conv_table(t_conv *tab)
{
	tab[0] = (t_conv){"%c", ft_print_c};
}

// General function which go through the string
int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		i;
	int		offset;
	t_conv	tab_conv[NB_CONVERTER];

	va_start(pa, format);
	init_conv_table(tab_conv);
	i = 0;
	while (*format)
	{
		offset = 1;
		if (*format == tab_conv[0].ph[0] && *(format + 1) == tab_conv[0].ph[1])
		{
			i += ft_print_c(pa);
			offset = 2;
		}
		else 
		{
			write(1, format, 1);
			i++;
		}
		format += offset;
	}
	return (i);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	char	c = 'a';
	char	*str = "ab%c\n";

	printf(str, c);
	ft_printf(str, c);
}
