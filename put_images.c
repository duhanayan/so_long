/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <dayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:14:16 by dayan             #+#    #+#             */
/*   Updated: 2022/04/12 02:14:17 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	put_c(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bg,
		game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.c,
		game->x, game->y);
}

void	put_e(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bg,
		game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.e,
		game->x, game->y);
}

void	put_p(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bg,
		game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.p,
		game->x, game->y);
}

void	put_w(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bg,
		game->x, game->y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.w,
		game->x, game->y);
}
