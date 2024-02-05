/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:47:43 by jlinguet          #+#    #+#             */
/*   Updated: 2023/12/19 17:33:45 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

int	ft_printf(const char *str, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr10(int nbr);
int	ft_putnbru(t_ulong nbr, char *base);

#endif
