/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:57:06 by jvander-          #+#    #+#             */
/*   Updated: 2021/08/27 11:40:41 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_treat(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	if (c == 'd')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	if (c == 'u')
		return (ft_putnbr_base_u(va_arg(args, unsigned int), "0123456789"));
	if (c == 'p')
	{	
		ft_putstr("0x");
		return (ft_putnbr_base_ull((unsigned long long)va_arg(args, void *),
				"0123456789abcdef") + 2);
	}
	if (c == 'x')
		return (ft_putnbr_base_u(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base_u(va_arg(args, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		to_ret;
	va_list	args;
	int		i;

	i = 0;
	to_ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{	
			to_ret += ft_putchar(str[i]);
			i++;
		}
		else
		{
			to_ret += ft_treat(str[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (to_ret);
}
