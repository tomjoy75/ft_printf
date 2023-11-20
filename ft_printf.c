/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:28:47 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/20 17:59:12 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NB_CONVERTER 6

static void	init_conv_table(t_conv *tab)
{
	tab[0] = (t_conv){"%c", ft_print_c};
	tab[1] = (t_conv){"%s", ft_print_str};
	tab[2] = (t_conv){"%%", ft_print_percent};
	tab[3] = (t_conv){"%i", ft_print_int};
	tab[4] = (t_conv){"%d", ft_print_int};
	tab[5] = (t_conv){"%u", ft_print_uint};
}
// Implement la fonction is_in_tab
//return length ou 0 si pas dans la tab

static int	is_in_tab(const char *format, t_conv *tab, va_list pa
						, int *str_size)
{
	int	tab_counter;
	int	length;

	tab_counter = 0;
	while (tab_counter < NB_CONVERTER)
	{
		if (*format == tab[tab_counter].ph[0]
			&& *(format + 1) == tab[tab_counter].ph[1])
		{
			length = tab[tab_counter].f(pa);
			*str_size += length;
			return (length);
		}
		tab_counter++;
	}
	return (0);
}

// General function which go through the string
int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		str_size;
	t_conv	tab_conv[NB_CONVERTER];

	va_start(pa, format);
	init_conv_table(tab_conv);
	str_size = 0;
	while (*format)
	{
		if (!is_in_tab(format, tab_conv, pa, &str_size))
		{
			ft_putchar(format[0]);
			str_size++;
			format++;
		}
		else
			format += 2;
	}
	return (str_size);
}

#include <stdio.h>
int	main(void)
{
	char	c = 'a';
	char	*s = "Tom";
	int	i = -1;
	char	*str = "%c is a char %s is a string %% is percent \n%i is int %d is decimal %u is unsigned\n";
	int	len;

	len = printf(str, c, s, i, i, i);
	printf("len string : %d\n\n", len);
	len = ft_printf(str, c, s, i, i, i);
	printf("len string : %d\n\n", len);
	return (0);
}
