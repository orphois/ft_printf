/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoflehn <jhoflehn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 09:29:05 by jhoflehn          #+#    #+#             */
/*   Updated: 2026/11/07 16:30:46 by jhoflehn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uphex(unsigned long n)
{
	char	*base;
	int		printed;

	base = "0123456789ABCDEF";
	printed = 0;
	if (n >= 16)
		printed += ft_uphex(n / 16);
	printed += write(1, &base[n % 16], 1);
	return (printed);
}

static int	ft_lowhex(unsigned long n)
{
	char	*base;
	int		printed;

	base = "0123456789abcdef";
	printed = 0;
	if (n >= 16)
		printed += ft_lowhex(n / 16);
	printed += write(1, &base[n % 16], 1);
	return (printed);
}

static int	ft_undec(unsigned long n)
{
	char	*base;
	int		printed;

	base = "0123456789";
	printed = 0;
	if (n >= 10)
		printed += ft_undec(n / 10);
	printed += write(1, &base[n % 10], 1);
	return (printed);
}

int	ft_putunsigned(va_list args, unsigned char ident)
{
	int				printed;
	unsigned long	n;

	printed = 0;
	n = (unsigned long)va_arg(args, unsigned int);
	if (ident == 'u')
		printed += ft_undec(n);
	else if (ident == 'x')
		printed += ft_lowhex(n);
	else if (ident == 'X')
		printed += ft_uphex(n);
	return (printed);
}
