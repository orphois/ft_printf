/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoflehn <jhoflehn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:05:57 by jhoflehn          #+#    #+#             */
/*   Updated: 2026/11/09 08:11:26 by jhoflehn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nb(long n)
{
	int		printed;
	char	*base;

	base = "0123456789";
	printed = 0;
	if (n >= 10)
		printed += ft_nb(n / 10);
	printed += write(1, &base[n % 10], 1);
	return (printed);
}

int	ft_putsigned(va_list args)
{
	int		printed;
	long	n;

	printed = 0;
	n = (long)va_arg(args, int);
	if (n < 0)
	{
		n = -n;
		printed += write(1, "-", 1);
	}
	printed += ft_nb(n);
	return (printed);
}
