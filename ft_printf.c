/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:28:47 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/17 18:36:52 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	print_percent(char *str)
{
	write (1, str + 1, 1);
	return (2);
}
	
int	print_char(char c)
{
	write (1, &c, 1);
	return (2);
}

// This func manage each case of % 
int	convert_arg(char *str, char *arg)
{
	int	offset;

	offset = 1;
	if (*(str + 1) == '%')
		offset = print_percent(str);
	else if (*(str + 1) == 'c')
		offset = print_char(c);
	
	return (offset);
}

// General function which go through the string
// If it meet a %, send the string and the arg to convert function
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	offset;

	va_start(args, format);
	while (*format)
	{
		offset = 1;
		if (*format == '%' && *(format + 1) == '%')
			offset = print_percent((char *)format);
		else if (*format == '%') 
			offset = convert_arg((char *)format, va_arg(args, char));//comment savoir le type de args?
		else 
			write(1, format, 1);
		format += offset;
	}
	return (1); //A corriger plus tard
}
int	main(int argc, char **argv)
{
	char	c = 'a';

	ft_printf("5=6%%%c\n", c);
}
