/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:42:53 by dayan             #+#    #+#             */
/*   Updated: 2022/02/26 16:42:58 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexabasamak(unsigned int x)
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

int	ft_printhexa(unsigned int x, const char input)
{
	if (x == 0)
		return (write(1, "0", 1));
	if (x >= 16)
	{
		ft_printhexa(x / 16, input);
		ft_printhexa(x % 16, input);
	}
	else
	{
		if (x <= 9)
			ft_printnbr(x);
		else
		{
			if (input == 'x')
				ft_printchr('a' + (x % 10));
			else if (input == 'X')
				ft_printchr('A' + (x % 10));
		}
	}
	return (ft_hexabasamak(x));
}

static char	*strfill(char *str, int i, long long nm, int sign)
{
	str[i] = '\0';
	while (i--)
	{
		str[i] = (nm % 10) + 48;
		nm /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_printf(int n)
{
	int			i;
	int			temp;
	long long	nm;
	char		*str;
	int			sign;

	sign = 1;
	i = 1;
	nm = (long long) n;
	if (nm < 0)
	{
		nm *= -1;
		sign *= -1;
		i++;
	}
	temp = nm;
	while (temp % 10 != temp)
	{
		temp /= 10;
		i++;
	}
	str = (char *) malloc ((i + 1) * sizeof(char));
	if (!str)
		return (0);
	return (strfill(str, i, nm, sign));
}
