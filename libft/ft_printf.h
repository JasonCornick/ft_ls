/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:18:22 by jcornick          #+#    #+#             */
/*   Updated: 2018/08/22 17:18:47 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_handle_arguments(const char *format, int i, va_list ar);
int		ft_handle_conver(char s, va_list a, long long int g, int i);
int		pr_putnbr(long long int n);
void	pr_putchar(char c);
char	*pr_itoa_base(long long int value, int base);
int		pr_putstr(const char *s);
char	*pr_tolower(char *s);
int		d_or_u(long long int arg, int i, char s);
int		o_or_x(int i, long long int arg, char *str, char s);
int		s_or_p(char *str, int i, long int pointer, char s);
int		ft_handle_conversion(char s, va_list a, long long int g, int i);
int		again(char s, va_list arguments, long long int arg, int i);
int		once_again(char s, va_list arguments, long long int arg, int i);

#endif
