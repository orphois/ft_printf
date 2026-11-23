/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoflehn <jhoflehn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:40:22 by jhoflehn          #+#    #+#             */
/*   Updated: 2026/11/09 08:08:01 by jhoflehn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(va_list args);
int	ft_putstr(va_list args);
int	ft_putptr(va_list args);
int	ft_putsigned(va_list args);
int	ft_putunsigned(va_list args, unsigned char ident);
int	ft_putpercent(void);

#endif
