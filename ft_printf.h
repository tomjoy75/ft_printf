/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:50:20 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/21 15:24:53 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_conv
{
	char	*ph;
	int		(*f)(va_list);
}		t_conv;

void	ft_putchar(int c);
size_t	ft_strlen(const char *s);
int		ft_print_c(va_list ap);
int		ft_print_str(va_list ap);
int		ft_print_percent(va_list ap);
int		ft_print_int(va_list ap);
int		ft_print_uint(va_list ap);
int		ft_print_hexa_lower(va_list ap);
int		ft_print_hexa_upper(va_list ap);
int		ft_print_ptr(va_list ap);
int		ft_printf(const char *format, ...);

#endif
