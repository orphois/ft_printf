/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoflehn <jhoflehn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:24 by jhoflehn          #+#    #+#             */
/*   Updated: 2026/11/09 08:09:33 by jhoflehn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_delegate(va_list args, unsigned char ident)
{
	int	printed;

	printed = 0;
	if (ident == 'c')
		printed += ft_putchar(args);
	if (ident == 's')
		printed += ft_putstr(args);
	if (ident == 'p')
		printed += ft_putptr(args);
	if (ident == 'd' || ident == 'i')
		printed += ft_putsigned(args);
	if (ident == 'u' || ident == 'x' || ident == 'X')
		printed += ft_putunsigned(args, ident);
	if (ident == '%')
		printed += ft_putpercent();
	return (printed);
}

static int	ft_invoke(va_list args, const char *str)
{
	size_t			i;
	int				printed;
	unsigned char	ident;

	i = 0;
	printed = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[++i])
		{
			ident = str[i++];
			printed += ft_delegate(args, ident);
		}
		else
		{
			write(1, &str[i++], 1);
			printed++;
		}
	}
	return (printed);
}

int	ft_printf(const	char *str, ...)
{
	va_list			args;
	int				printed;

	printed = 0;
	va_start(args, str);
	printed += ft_invoke(args, str);
	va_end(args);
	return (printed);
}
