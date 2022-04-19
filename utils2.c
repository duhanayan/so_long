/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <dayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:02:50 by dayan             #+#    #+#             */
/*   Updated: 2022/04/12 01:02:51 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	close_frame(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
	return (1);
}

char	**read_map(t_game *game, char *yol)
{
	int	path;

	path = open(yol, O_RDONLY);
	if (path == -1)
		return (0);
	game->map_file = get_next_line(path);
	game->map = ft_split(game->map_file, '\n');
	game -> h = row_count(game->map_file) * 64;
	game -> w = ft_strlen(game->map[0]) * 64;
	return (game->map);
}

void	images(t_game *game)
{
	int	x;
	int	y;

	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &x, &y);
	game->img.wallwhite = mlx_xpm_file_to_image(game->mlx,
			"./img/wallwhite.xpm", &x, &y);
	game->img.bg = mlx_xpm_file_to_image(game->mlx, "./img/bg.xpm", &x, &y);
	game->img.c = mlx_xpm_file_to_image(game->mlx, "./img/c.xpm", &x, &y);
	game->img.e = mlx_xpm_file_to_image(game->mlx, "./img/e.xpm", &x, &y);
	game->img.p = mlx_xpm_file_to_image(game->mlx, "./img/p.xpm", &x, &y);
	game->img.w = mlx_xpm_file_to_image(game->mlx, "./img/w.xpm", &x, &y);
}

t_game	*find_p(t_game *game)
{
	int	i;
	int	j;

	game->player.column = 0;
	game->player.row = 0;
	i = 0;
	while (game->map[i] != 0)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				return (game);
			game->player.column++;
			j++;
		}
		game->player.column = 0;
		game->player.row++;
		i++;
	}
	return (game);
}

int	find_c(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != 0)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
