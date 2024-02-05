/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:40:09 by jlinguet          #+#    #+#             */
/*   Updated: 2023/12/20 12:22:42 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_uint	ft_strlen(char *s)
{
	t_uint	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr10(int nbr)
{
	int		len;
	char	c;

	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648"));
	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		len += ft_putnbr10(nbr / 10);
	c = nbr % 10 + '0';
	return (ft_putchar(c) + len);
}

int	ft_putnbru(unsigned long nbr, char *base)
{
	int		len;
	t_uint	base_len;
	char	c;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
			len += ft_putnbru(nbr / base_len, base);
	c = base[nbr % base_len];
	return (ft_putchar(c) + len);
}
