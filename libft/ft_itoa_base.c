/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:52:50 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 14:28:35 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			sizecount(int value, int base, int flag)
{
	int		size;

	size = 0;
	while (value != 0)
	{
		value = value / base;
		size++;
	}
	size--;
	size = size + flag;
	return (size);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*tab;
	int		size;
	int		flag;

	tab = "0123456789ABCDEF";
	flag = 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0)
	{
		value = value * -1;
		flag = (base == 10) ? 1 : 0;
	}
	size = sizecount(value, base, flag);
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size + 1] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (value > 0)
	{
		str[size--] = tab[value % base];
		value = value / base;
	}
	return (str);
}
