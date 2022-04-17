/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <dayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:17:24 by dayan             #+#    #+#             */
/*   Updated: 2022/04/12 01:17:35 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	moves_a(t_game *game)
{
	if (game->map[game->player.row][game->player.column - 1] == 'E'
		&& !find_c(game))
	{
		printf("You Won!\n");
		close_frame(game);
	}
	else if (game->map[game->player.row][game->player.column - 1] == 'W')
	{
		printf("You Lost!\n");
		close_frame(game);
	}
	if (game->map[game->player.row][game->player.column - 1] != '1'
	&& game->map[game->player.row][game->player.column - 1] != 'E')
	{
		game->map[game->player.row][game->player.column] = '0';
		game->map[game->player.row][game->player.column - 1] = 'P';
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	moves_s(t_game *game)
{
	if (game->map[game->player.row + 1][game->player.column] == 'E'
		&& !find_c(game))
	{
		printf("You Won!\n");
		close_frame(game);
	}
	else if (game->map[game->player.row + 1][game->player.column] == 'W')
	{
		printf("You Lost!\n");
		close_frame(game);
	}
	if (game->map[game->player.row + 1][game->player.column] != '1'
	&& game->map[game->player.row + 1][game->player.column] != 'E')
	{
		game->map[game->player.row][game->player.column] = '0';
		game->map[game->player.row + 1][game->player.column] = 'P';
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	moves_d(t_game *game)
{
	if (game->map[game->player.row][game->player.column + 1] == 'E'
		&& !find_c(game))
	{
		printf("You Won!\n");
		close_frame(game);
	}
	else if (game->map[game->player.row][game->player.column + 1] == 'W')
	{
		printf("You Lost!\n");
		close_frame(game);
	}
	if (game->map[game->player.row][game->player.column + 1] != '1'
	&& game->map[game->player.row][game->player.column + 1] != 'E')
	{
		game->map[game->player.row][game->player.column] = '0';
		game->map[game->player.row][game->player.column + 1] = 'P';
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	moves_w(t_game *game)
{
	if (game->map[game->player.row - 1][game->player.column] == 'E'
		&& !find_c(game))
	{
		printf("You Won!\n");
		close_frame(game);
	}
	else if (game->map[game->player.row - 1][game->player.column] == 'W')
	{
		printf("You Lost!\n");
		close_frame(game);
	}
	if (game->map[game->player.row - 1][game->player.column] != '1'
	&& game->map[game->player.row - 1][game->player.column] != 'E')
	{
		game->map[game->player.row][game->player.column] = '0';
		game->map[game->player.row - 1][game->player.column] = 'P';
		game->moves++;
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}
