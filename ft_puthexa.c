/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:56:08 by azrig             #+#    #+#             */
/*   Updated: 2025/01/06 02:59:23 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char format)
{
	char	*alpha;
	int		count;

	alpha = "0123456789abcdef";
	if (format == 'X')
		alpha = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
	{
		count += ft_puthexa(n / 16, format);
		count += ft_puthexa(n % 16, format);
	}
	else
		count += ft_putchar(alpha[n]);
	return (count);
}
