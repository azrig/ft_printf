/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:57:44 by azrig             #+#    #+#             */
/*   Updated: 2025/01/09 10:33:21 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n > 9)
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
		count += ft_putnbr(n);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
