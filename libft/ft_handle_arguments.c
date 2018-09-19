/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:02:59 by jcornick          #+#    #+#             */
/*   Updated: 2018/08/22 17:18:04 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_handle_arguments(const char *format, int i, va_list ar)
{
	int				a;
	long long int	arg;

	arg = 0;
	a = 0;
	while (format[i] != 's' && format[i] != 'S' && format[i] != 'p' &&
			format[i] != 'd' && format[i] != 'D' && format[i] != 'i' &&
			format[i] != 'o' && format[i] != 'O' && format[i] != 'u' &&
			format[i] != 'U' && format[i] != 'x' && format[i] != 'X' &&
			format[i] != 'c' && format[i] != 'C' && format[i] != '%' &&
			format[i] != '\0')
	{
		i++;
	}
	i = ft_handle_conver(format[i], ar, arg, a);
	return (i);
}

int					ft_handle_conver(char s, va_list a, long long int g, int i)
{
	if (s == 'd' || s == 'D' || s == 'i' || s == 'u' || s == 'U' ||
			s == 'o' || s == 'O' || s == 'x' || s == 'X')
		i = i + again(s, a, g, i);
	if (s == 'c' || s == 'C' || s == 's' || s == 'S' || s == 'p' || s == '%')
		i = i + once_again(s, a, g, i);
	return (i);
}
