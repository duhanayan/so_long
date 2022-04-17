/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <dayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:11:30 by dayan             #+#    #+#             */
/*   Updated: 2022/04/12 01:11:32 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	put_image(t_game *game, int row, int column)
{
	if (game->map[row][column] == '1')
	{
		if (row == 0 && column == 0)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->img.wallwhite, game->x, game->y);
		}
		else
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.wall,
				game->x, game->y);
	}
	if (game->map[row][column] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bg,
			game->x, game->y);
	if (game->map[row][column] == 'C')
		put_c(game);
	if (game->map[row][column] == 'E')
		put_e(game);
	if (game->map[row][column] == 'P')
		put_p(game);
	if (game->map[row][column] == 'W')
		put_w(game);
}

void	render_map(t_game *game)
{
	int		row;
	int		column;
	char	*str;
	char	*moves;

	game->y = 0;
	row = 0;
	while (game->map[row] != 0)
	{
		column = 0;
		game->x = 0;
		while (game->map[row][column] != '\0')
		{
			put_image(game, row, column);
			column++;
			game->x += 64;
		}
		game->y += 64;
		row++;
	}
	moves = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", moves);
	mlx_string_put(game->mlx, game->mlx_win, 1, 10, 250, str);
	free(str);
	free(moves);
}

int	walk(int input, t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	find_p(game);
	if (input == 0)
		moves_a(game);
	else if (input == 1)
		moves_s(game);
	else if (input == 2)
		moves_d(game);
	else if (input == 13)
		moves_w(game);
	else if (input == 53)
		close_frame(game);
	render_map(game);
	return (input);
}

int	check_map_name(char *str)
{
	char	*i;
	char	*x;

	x = ".ber";
	i = ft_strrchr(str, '.');
	if (!i)
		return (0);
	if (ft_strncmp(i, x, ft_strlen(str)))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.moves = 0;
	if (argc != 2)
		return (invalid_map());
	if (!check_map_name(argv[1]))
		return (invalid_map());
	game.mlx = mlx_init();
	game.map = read_map(&game, argv[1]);
	if (!check_map(&game))
		return (0);
	game.mlx_win = mlx_new_window(game.mlx, game.w, game.h, "so_long");
	images(&game);
	render_map(&game);
	mlx_hook(game.mlx_win, 2, (1L << 0), walk, &game);
	mlx_hook(game.mlx_win, 17, 0, close_frame, &game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_loop(game.mlx);
}
