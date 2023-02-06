/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:52:06 by enoviell          #+#    #+#             */
/*   Updated: 2023/02/05 19:39:36 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int n)
{
	long int	nbr;
	int			len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len += ft_putchar('-');
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
	}
	len += ft_putnbr(nbr % 10 + 48);
	return (len);
}

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += ft_putnbr(n);
	return (len);
}

int	ft_printunsigned(unsigned int unsnbr)
{
	int	len;

	len = 0;
	if (unsnbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len += ft_putnbr(unsnbr);
	return (len);
}
