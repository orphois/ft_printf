/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoflehn <jhoflehn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 10:31:33 by jhoflehn          #+#    #+#             */
/*   Updated: 2026/11/09 08:11:12 by jhoflehn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long n)
{
	char	*base;
	int		printed;

	printed = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		printed += ft_puthex(n / 16);
	printed += write(1, &base[n % 16], 1);
	return (printed);
}

int	ft_putptr(va_list args)
{
	unsigned long	ptr;
	int				printed;

	printed = 0;
	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	printed += write(1, "0x", 2);
	printed += ft_puthex(ptr);
	return (printed);
}
