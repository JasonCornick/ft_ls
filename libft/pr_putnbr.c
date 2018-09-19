/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:20:59 by jcornick          #+#    #+#             */
/*   Updated: 2018/08/22 17:21:02 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					pr_putnbr(long long int n)
{
	long long int	nbr;
	unsigned int	size;
	int				i;

	i = 0;
	size = 1;
	if (n < 0)
		n = n * -1;
	nbr = n;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size = size * 10;
		i++;
	}
	while (size > 0)
	{
		pr_putchar((n / size) + 48);
		n = n % size;
		size = size / 10;
	}
	return (i);
}
