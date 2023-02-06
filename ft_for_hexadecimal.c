/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:11:40 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/05 19:40:49 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenhex(unsigned int n)
{
	int	len;

	len = 0;
	if (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_putnbrhex(unsigned int hex, const char format)
{
	if (hex >= 16)
	{
		ft_putnbrhex(hex / 16, format);
		ft_putnbrhex(hex % 16, format);
	}
	else
	{
		if (hex > 9 && format == 'x')
			ft_putchar(hex - 10 + 'a');
		if (hex > 9 && format == 'X')
			ft_putchar(hex - 10 + 'A');
		else if (hex <= 9)
			ft_putchar(hex + 48);
	}
}

int	ft_printhex(unsigned int hex, const char format)
{
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_putnbrhex(hex, format);
	return (ft_lenhex(hex));
}
