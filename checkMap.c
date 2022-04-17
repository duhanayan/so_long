/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <dayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:51:28 by dayan             #+#    #+#             */
/*   Updated: 2022/04/12 00:51:31 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_elements(char *str)
{
	int		i;
	int		x;
	int		y;
	char	depo[3];

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P' && !ft_strchr(depo, 'P'))
			depo[x++] = str[i];
		else if (str[i] == 'C' && !ft_strchr(depo, 'C'))
			depo[x++] = str[i];
		else if (str[i] == 'E' && !ft_strchr(depo, 'E'))
			depo[x++] = str[i];
		else if (str[i] == 'W' && !ft_strchr(depo, 'W'))
			depo[x++] = str[i];
		i++;
	}
	depo[x] = '\0';
	y = ft_strlen(depo);
	if (y != 4)
		return (0);
	return (1);
}

int	check_borders(t_game *game)
{
	int	i;
	int	x;
	int	size;

	size = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[0] && i != size)
		if (game->map[0][i++] != '1')
			return (0);
	i = 0;
	while (game->map[game->h / 64 - 1] && i != size)
		if (game->map[game->h / 64 - 1][i++] != '1')
			return (0);
	x = 0;
	while (game->map[x])
		if (game->map[x++][0] != '1')
			return (0);
	x = 0;
	while (game->map[x])
		if (game->map[x++][size - 1] != '1')
			return (0);
	return (1);
}

int	check_shape(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	x = ft_strlen(game->map[0]);
	while (game->map[y])
		y++;
	if (x == y)
		return (0);
	i = 0;
	while (game->map[i] && i < row_count(game->map_dosya) - 1)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_units(char *mapDosya)
{
	int	i;

	i = 0;
	while (mapDosya[i] != '\0')
	{
		if (mapDosya[i] != '0' && mapDosya[i] != '1' && mapDosya[i] != 'P'
			&& mapDosya[i] != 'E' && mapDosya[i] != 'C' && mapDosya[i] != 'W'
			&& mapDosya[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!game->map)
		return (invalid_map());
	if (!check_elements(game->map_dosya))
		return (invalid_map());
	if (!check_borders(game))
		return (invalid_map());
	if (!check_shape(game))
		return (invalid_map());
	if (!check_units(game->map_dosya))
		return (invalid_map());
	if (!check_p(game->map_dosya))
		return (invalid_map());
	return (1);
}
