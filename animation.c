/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:39:10 by dayan             #+#    #+#             */
/*   Updated: 2022/04/17 15:39:12 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	animation_enemy_right(t_game *game)
{
	find_w(game);
	if (game->map[game->enemy.row][game->enemy.column + 1] != '1'
	&& game->map[game->enemy.row][game->enemy.column + 1] != 'C'
	&& game->map[game->enemy.row][game->enemy.column + 1] != 'E'
	&& game->map[game->enemy.row][game->enemy.column + 1] != 'W')
	{
		if (game->map[game->enemy.row][game->enemy.column + 1] == 'P')
		{
			ft_printf("You Lost!\n");
			close_frame(game);
		}
		game->map[game->enemy.row][game->enemy.column] = '0';
		game->map[game->enemy.row][game->enemy.column + 1] = 'W';
	}
	else
		game->z = 1001;
}

void	animation_enemy_left(t_game *game)
{
	find_w(game);
	if (game->map[game->enemy.row][game->enemy.column - 1] != '1'
		&& game->map[game->enemy.row][game->enemy.column - 1] != 'C'
		&& game->map[game->enemy.row][game->enemy.column - 1] != 'E'
		&& game->map[game->enemy.row][game->enemy.column - 1] != 'W')
	{
		if (game->map[game->enemy.row][game->enemy.column - 1] == 'P')
		{
			ft_printf("You Lost!\n");
			close_frame(game);
		}
		game->map[game->enemy.row][game->enemy.column] = '0';
		game->map[game->enemy.row][game->enemy.column - 1] = 'W';
	}
	else
		game->z = 1;
}

int	animation(t_game *game)
{
	int	x;
	int	y;

	if (game->z >= 1 && game->z <= 1000)
	{
		game->img.p = mlx_xpm_file_to_image(game->mlx, "./img/p2.xpm", &x, &y);
		animation_enemy_right(game);
	}
	if (game->z >= 1001 && game->z <= 2000)
	{
		game->img.p = mlx_xpm_file_to_image(game->mlx, "./img/p.xpm", &x, &y);
		animation_enemy_left(game);
	}
	render_map(game);
	if (game->z >= 2001)
		game->z = 0;
	game->z++;
	return (0);
}

t_game	*find_w(t_game *game)
{
	int	i;
	int	j;

	game->enemy.column = 0;
	game->enemy.row = 0;
	i = 0;
	while (game->map[i] != 0)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'W')
				return (game);
			game->enemy.column++;
			j++;
		}
		game->enemy.column = 0;
		game->enemy.row++;
		i++;
	}
	return (game);
}
