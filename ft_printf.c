/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:28:47 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/19 12:32:26 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define NB_CONVERTER 2

static void	init_conv_table(t_conv *tab)
{
	tab[0] = (t_conv){"%c", ft_print_c};
	tab[1] = (t_conv){"%s", ft_print_str};
}
// Implement la fonction is_in_tab
//return length ou 0 si pas dans la tab
static int	is_in_tab(char *format, t_conv tab, va_list pa)
{
	int	tab_counter;
	int	length;


// General function which go through the string
int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		str_size;
	int		tab_counter;
	t_conv	tab_conv[NB_CONVERTER];

	va_start(pa, format);
	init_conv_table(tab_conv);
	str_size = 0;
	while (*format)
	{
		tab_counter = 0;
		while (tab_counter < NB_CONVERTER)
		{	
			if (*format == tab_conv[tab_counter].ph[0] && *(format + 1) == tab_conv[tab_counter].ph[1])
			{
				str_size += tab_conv[tab_counter].f(pa);
				format += 2;
				break;
			}
			tab_counter++;
		}
		if (tab_counter == NB_CONVERTER) 
		{
//			write(1, format, 1);
			ft_putchar(format[0]);
			str_size++;
			format++;
		}
	}
	return (str_size);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	char	c = 'a';
	char	*s = "Tom";
	char	*str = "%c is a char %s is a string\n";
	int	len;

	len = printf(str, c, s);
	printf("len string : %d\n\n", len);
	len = ft_printf(str, c, s);
	printf("len string : %d\n\n", len);
}
