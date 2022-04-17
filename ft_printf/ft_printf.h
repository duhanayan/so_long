/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:33:03 by dayan             #+#    #+#             */
/*   Updated: 2022/02/26 16:33:04 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printstr(char *str);
int		ft_printchr(int c);
int		ft_printnbr(long int x);
int		ft_printunbr(unsigned int x);
int		ft_printhexa(unsigned int x, const char i);
char	*ft_uitoa(unsigned int x);
int		ft_printp(unsigned long int x);
int		ft_printhexap(unsigned long int x);
int		ft_hexabasamakp(unsigned long int x);
char	*ft_itoa_printf(int n);
size_t	ft_strlen_printf(const char *str);
int		ft_nbrkontrol(long int x, char c);
int		ft_printunbr(unsigned int x);
int		ft_printnbr(long int x);
int		ustfonk(va_list ap, const char *input, int sayi, int i);
int		ft_printf(const char *input, ...);

#endif
