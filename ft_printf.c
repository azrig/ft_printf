/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:48:14 by azrig             #+#    #+#             */
/*   Updated: 2025/01/12 15:58:35 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list arg, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar((char)va_arg(arg, int));
	else if (format == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		count += ft_putun(va_arg(arg, unsigned int));
	else if (format == 'p')
		count += ft_putptr(va_arg(arg, void *));
	else if (format == 'x' || format == 'X')
		count += ft_puthexa(va_arg(arg, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	if (str == NULL)
		return (-1);
	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check(arg, str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
