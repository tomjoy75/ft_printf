/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:53:19 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/19 11:10:46 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
