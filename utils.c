/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <dayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:52:11 by dayan             #+#    #+#             */
/*   Updated: 2022/04/12 00:52:13 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_p(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			x++;
		i++;
	}
	if (x != 1)
		return (0);
	return (1);
}

int	row_count(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			x++;
		i++;
	}
	return (x);
}

void	*myfree(void *f)
{
	free(f);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	buff;
	char	*line;
	int		ret;
	int		i;

	buff = 0;
	line = (char *)malloc(sizeof(char) * 9999);
	ret = 1;
	i = 0;
	while (ret > 0)
	{
		ret = read(fd, &buff, 1);
		if (ret <= 0)
			break ;
		line[i++] = buff;
	}
	line[i] = 0;
	if (!*line)
		return (myfree(line));
	return (line);
}

int	invalid_map(void)
{
	ft_printf("Invalid Map\n");
	return (0);
}
