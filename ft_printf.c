/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:41:06 by jlinguet          #+#    #+#             */
/*   Updated: 2023/12/19 17:24:38 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_p(va_list ap)
{
	t_ulong	arg;

	arg = va_arg(ap, t_ulong);
	if (!arg)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbru(arg, "0123456789abcdef"));
}

static int	print_conv(char c, va_list ap)
{
	int	len;

	if (c == 'c')
		len = ft_putchar((char)va_arg(ap, int));
	else if (c == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		len = ft_putnbr10(va_arg(ap, int));
	else if (c == 'u')
		len = ft_putnbru(va_arg(ap, t_uint), "0123456789");
	else if (c == 'x')
		len = ft_putnbru(va_arg(ap, t_uint), "0123456789abcdef");
	else if (c == 'X')
		len = ft_putnbru(va_arg(ap, t_uint), "0123456789ABCDEF");
	else if (c == 'p')
		len = conv_p(ap);
	else if (c == '%')
		len = ft_putchar('%');
	else
		len = ft_putchar('%') + ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	if (!str)
		return (-1);
	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!*(str + 1))
				return (-1);
			len += print_conv(*(str + 1), ap);
			str += 2;
		}
		else
		{
			ft_putchar(*str);
			str++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
