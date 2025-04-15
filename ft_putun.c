/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:50:06 by azrig             #+#    #+#             */
/*   Updated: 2025/01/09 10:32:49 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putun(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putun((n / 10));
		count += ft_putun((n % 10));
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
