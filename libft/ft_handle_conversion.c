/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:25:27 by jcornick          #+#    #+#             */
/*   Updated: 2018/08/22 17:29:33 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				d_or_u(long long int arg, int i, char s)
{
	if (s == 'd' || s == 'D' || s == 'i')
	{
		if (arg < 0)
		{
			pr_putchar('-');
			i++;
		}
		i++;
		i = i + pr_putnbr(arg);
	}
	if (s == 'u' || s == 'U')
	{
		i++;
		if (arg < 0)
			i = i + pr_putnbr(arg + 4294967295);
		else
			i = i + pr_putnbr(arg);
	}
	return (i);
}

int				o_or_x(int i, long long int arg, char *str, char s)
{
	if (s == 'o' || s == 'O')
	{
		if (arg < 0)
			str = pr_itoa_base(arg + 4294967295, 8);
		else
			str = pr_itoa_base(arg, 8);
		i++;
		i = i + pr_putstr(str);
		free(str);
	}
	if (s == 'x' || s == 'X')
	{
		if (arg > 4294967295 || arg == 0)
			pr_putchar('0');
		if (arg <= 4294967295 && arg != 0)
		{
			str = pr_itoa_base(arg, 16);
			if (s == 'x')
				str = pr_tolower(str);
			i = i + pr_putstr(str);
			free(str);
		}
		i++;
	}
	return (i);
}

int				s_or_p(char *str, int i, long int pointer, char s)
{
	if (s == 's' || s == 'S')
	{
		if (str == NULL)
			str = "(null)";
		i++;
		i = i + pr_putstr(str);
	}
	if (s == 'p')
	{
		str = pr_itoa_base(pointer, 16);
		str = pr_tolower(str);
		pr_putstr("0x");
		i = 2;
		i = i + pr_putstr(str);
		free(str);
		i++;
	}
	return (i);
}

int				again(char s, va_list arguments, long long int arg, int i)
{
	char		*str;

	str = NULL;
	if (s == 'd' || s == 'D' || s == 'i')
	{
		arg = va_arg(arguments, int);
		i = i + d_or_u(arg, i, s);
	}
	if (s == 'u' || s == 'U')
	{
		arg = va_arg(arguments, unsigned int);
		i = i + d_or_u(arg, i, s);
	}
	if (s == 'o' || s == 'O')
	{
		arg = va_arg(arguments, unsigned int);
		i = i + o_or_x(i, arg, str, s);
	}
	if (s == 'x' || s == 'X')
	{
		arg = va_arg(arguments, long long int);
		i = i + o_or_x(i, arg, str, s);
	}
	va_end(arguments);
	return (i);
}

int				once_again(char s, va_list arguments, long long int arg, int i)
{
	char		*str;
	long int	pointer;

	pointer = 0;
	if (s == 'c' || s == 'C')
	{
		arg = va_arg(arguments, int);
		pr_putchar(arg);
	}
	if (s == 's' || s == 'S')
	{
		str = va_arg(arguments, char *);
		i = (i + s_or_p(str, i, pointer, s)) - 1;
	}
	if (s == 'p')
	{
		pointer = (long)(va_arg(arguments, void *));
		i = (i + s_or_p(str, i, pointer, s)) - 1;
	}
	if (s == '%')
		pr_putchar('%');
	va_end(arguments);
	i++;
	return (i);
}
