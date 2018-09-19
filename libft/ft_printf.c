/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:06:36 by jcornick          #+#    #+#             */
/*   Updated: 2018/08/22 17:19:35 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_string(int i, int a, va_list arguments, const char *format)
{
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			a = a + ft_handle_arguments(format, i, arguments);
			while (format[i] != 's' && format[i] != 'S' && format[i] != 'p' &&
					format[i] != 'd' && format[i] != 'D' && format[i] != 'i' &&
					format[i] != 'o' && format[i] != 'O' && format[i] != 'u' &&
					format[i] != 'U' && format[i] != 'x' && format[i] != 'X' &&
					format[i] != 'c' && format[i] != 'C' && format[i] != '%' &&
					format[i] != '\0')
				i++;
		}
		else
			a = a + write(1, &format[i], 1);
		if (format[i] != '\0')
			i++;
	}
	va_end(arguments);
	return (a);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	arguments;
	int		a;

	i = 0;
	a = 0;
	va_start(arguments, format);
	a = a + handle_string(i, a, arguments, format);
	return (a);
}
