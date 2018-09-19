/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:19:55 by jcornick          #+#    #+#             */
/*   Updated: 2018/08/22 17:23:02 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			size_count(long long int value, int base)
{
	int		size;

	size = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / base;
		size++;
	}
	size--;
	return (size);
}

char		*pr_itoa_base(long long int value, int base)
{
	char	*str;
	char	*tab;
	int		size;
	int		flag;

	tab = "0123456789ABCDEF";
	flag = 0;
	if (base < 2 || base > 16)
		return (0);
	size = size_count(value, base);
	str = (char *)malloc(sizeof(char) * size + flag + 1);
	if (value == 0)
	{
		size = 0;
		str[size] = tab[value];
	}
	size = size + flag;
	str[size + 1] = '\0';
	while (value != 0)
	{
		str[size] = tab[value % base];
		size--;
		value = value / base;
	}
	return (str);
}
