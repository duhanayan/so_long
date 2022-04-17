/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:49:12 by dayan             #+#    #+#             */
/*   Updated: 2022/02/26 16:49:13 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_basamak(unsigned int x)
{
	int	len;

	len = 0;
	while (x != 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int x)
{
	char	*str;
	int		len;

	len = ft_basamak(x);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (x != 0)
	{
		str[len - 1] = (x % 10) + '0';
		len--;
		x /= 10;
	}
	return (str);
}

int	ft_printstr(char *str)
{
	int	i;
	int	sayi;

	sayi = 0;
	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		sayi += write(1, &str[i], 1);
		i++;
	}
	return (sayi);
}

int	ft_printchr(int c)
{
	write(1, &c, 1);
	return (1);
}
