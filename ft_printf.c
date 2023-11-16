/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:28:47 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/16 15:56:22 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// This func manage each case of % 
int	convert(char *str, char *arg)
{
	if (*(str + 1) == '%')
	{
		write (1, str + 1, 1);
		return (2);
	}
	return (1);
}

// General function which go through the string
// If it meet a %, send the string and the arg to convert function
int	ft_printf(const char *format, ...)
{
	int	offset;

	while (*format)
	{
		offset = 1;
		if (*format == '%')
			offset = convert((char *)format, NULL);
		else 
			write(1, format, 1);
		format += offset;
	}
	return (1); //A corriger plus tard
}
int	main(int argc, char **argv)
{
	ft_printf("5=6%%\n");
}
