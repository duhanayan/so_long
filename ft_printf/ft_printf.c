/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:38:08 by dayan             #+#    #+#             */
/*   Updated: 2022/02/26 16:38:09 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ustfonk(va_list ap, const char *input, int sayi, int i)
{
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			if (input[i] == 's')
				sayi += ft_printstr(va_arg(ap, char *));
			else if (input[i] == 'd' || input[i] == 'i' || input[i] == 'u')
				sayi += ft_nbrkontrol(va_arg(ap, long int), input[i]);
			else if (input[i] == 'p')
				sayi += ft_printp(va_arg(ap, unsigned long int));
			else if (input[i] == 'c')
				sayi += ft_printchr(va_arg(ap, int));
			else if (input[i] == '%')
				sayi += ft_printchr('%');
			else if (input[i] == 'x' || input[i] == 'X')
				sayi += ft_printhexa(va_arg(ap, unsigned int), input[i]);
		}
		else
			sayi += ft_printchr(input[i]);
		i++;
	}
	return (sayi);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		sayi;
	int		i;

	i = 0;
	sayi = 0;
	va_start(ap, input);
	sayi = ustfonk(ap, input, sayi, i);
	va_end(ap);
	return (sayi);
}
