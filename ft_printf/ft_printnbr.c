/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:49:27 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/06/07 16:43:41 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nbr)
{
	long long int	n;
	int				len;

	n = nbr;
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar('-');
	}
	if (!(n >= 0 && n <= 9))
	{
		len += ft_putnbr(n / 10);
	}
	len += ft_putchar((n % 10) + 48);
	return (len);
}

int	ft_printnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	len += ft_putnbr(nbr);
	return (len);
}

int	ft_print_unsigned(unsigned int unbr)
{
	int	len;

	len = 0;
	if (unbr == 0)
		return (write(1, "0", 1));
	len += ft_putnbr(unbr);
	return (len);
}
