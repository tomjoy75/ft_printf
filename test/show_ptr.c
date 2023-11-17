/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:48:26 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/17 13:25:12 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	a = 5;
	char	c = a + 48;
	int	*adr = &a;
	char *	adr_c = (char *)adr;

	printf("a vaut %d\nson emplacement est %p\n", a, &a);
	write(1, &c, 1);
	write(1, &adr_c, 1);
}


