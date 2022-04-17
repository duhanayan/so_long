/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:49:20 by dayan             #+#    #+#             */
/*   Updated: 2022/02/26 16:49:21 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long int x)
{
	char	*str;
	int		sayi;

	sayi = 0;
	str = ft_itoa_printf(x);
	sayi = ft_strlen_printf(str);
	ft_printstr(str);
	free(str);
	return (sayi);
}

int	ft_printunbr(unsigned int x)
{
	char	*str;
	int		sayi;

	sayi = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = ft_uitoa(x);
	ft_printstr(str);
	sayi = ft_strlen_printf(str);
	free(str);
	return (sayi);
}

int	ft_nbrkontrol(long int x, char c)
{
	int	sayi;

	sayi = 0;
	if (c == 'd' || c == 'i')
		sayi += ft_printnbr(x);
	else if (c == 'u')
		sayi += ft_printunbr(x);
	return (sayi);
}
