/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:50:20 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/18 22:57:24 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_conv
{
	char	*ph;
	int	(*f)(va_list);
}		t_conv;

void	ft_putchar(int c);
size_t	ft_strlen(const char *s);
int	ft_print_c(va_list ap);

#endif
