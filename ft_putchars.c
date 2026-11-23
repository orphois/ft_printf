/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoflehn <jhoflehn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:15:55 by jhoflehn          #+#    #+#             */
/*   Updated: 2026/11/09 08:10:24 by jhoflehn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(va_list args)
{
	int		printed;
	char	*str;

	printed = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[printed])
	{
		write(1, &str[printed], 1);
		printed++;
	}
	return (printed);
}

int	ft_putpercent(void)
{
	return (write(1, "%", 1));
}
