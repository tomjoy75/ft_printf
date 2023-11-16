/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:21:19 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/16 13:26:00 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	add(int num, ...) 
{
	va_list	args;
	va_start(args, num);
	int sum = 0;
	int i = 0;
	while (i < num)
	{
		int a = va_arg(args, int);
		printf("Nb %d : %d\n", i, a);
		sum += a;
		i++;
	}
	va_end(args);
	return (sum);
}

int	main(void)
{
	printf("Sum : %d\n", add(5, 5, 2, 4, 55, 2));
}

