/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:45:52 by dayan             #+#    #+#             */
/*   Updated: 2022/02/26 16:45:53 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexabasamakp(unsigned long int x)
{
	int	i;

	i = 0;
	while (x != 0)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

int	ft_printhexap(unsigned long int x)
{
	if (x >= 16)
	{
		ft_printhexap(x / 16);
		ft_printhexap(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_printnbr(x);
		else
			ft_printchr('a' + (x % 10));
	}
	return (ft_hexabasamakp(x));
}

int	ft_printp(unsigned long int x)
{
	int	sayi;

	sayi = 0;
	if (x == 0)
		return (write(1, "0x0", 3));
	else
	{
		sayi += write(1, "0x", 2);
		sayi += ft_printhexap(x);
	}
	return (sayi);
}

size_t	ft_strlen_printf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
