/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <dayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:10:39 by dayan             #+#    #+#             */
/*   Updated: 2022/04/12 01:10:40 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_player
{
	int	row;
	int	column;
}	t_player;

typedef struct s_enemy
{
	int	row;
	int	column;
}	t_enemy;

typedef struct s_img
{
	void	*bg;
	void	*floor;
	void	*p;
	void	*wall;
	void	*wallwhite;
	void	*c;
	void	*e;
	void	*w;

}	t_img;

typedef struct s_game
{
	t_img		img;
	t_player	player;
	t_enemy		enemy;
	size_t		h;
	size_t		w;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	char		*map_file;
	int			x;
	int			y;
	int			z;
	int			moves;

}	t_game;

int			invalid_map(void);
int			check_map(t_game *game);
char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);
int			row_count(char *str);
t_game		*find_p(t_game *game);
void		render_map(t_game *game);
int			find_c(t_game *game);
void		images(t_game *game);
char		**read_map(t_game *game, char *yol);
int			close_frame(t_game *game);
void		moves_a(t_game *game);
void		moves_s(t_game *game);
void		moves_d(t_game *game);
void		moves_w(t_game *game);
void		put_c(t_game *game);
void		put_e(t_game *game);
void		put_p(t_game *game);
void		put_image(t_game *game, int row, int column);
int			check_p(char *str);
int			check_map_2(t_game *game);
int			check_elements(char *str);
int			check_borders(t_game *game);
void		put_w(t_game *game);
int			animation(t_game *game);
t_game		*find_w(t_game *game);
#endif
