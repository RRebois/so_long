/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:27:43 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 15:07:32 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/incs/libft.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_coord
{
	char	*filename;
	size_t	x;
	size_t	y;
}				t_coord;

typedef struct s_game
{
	char	**map;
	char	*mappy;
	size_t	width;
	size_t	height;
	t_coord	p;
	t_coord	e;
	size_t	items;
}				t_game;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_game	data;
}				t_var;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	LEFT = 0,
	DOWN = 1,
	RIGHT = 2,
	UP = 13,
	ESC = 53
};

int		close_game(t_var *v);
int		main(int ac, char **av);
int		check_valid_map(t_game *game);
int		check_valid_path(t_game *game);
void	hooks(t_var *v);
void	key_up(t_var *v);
void	key_left(t_var *v);
void	key_down(t_var *v);
void	key_right(t_var *v);
void	count_check(int i, t_var *v);
void	moveup_c(t_var *v);
void	moveup_e(t_var *v);
void	moveup_v(t_var *v);
void	movedown_c(t_var *v);
void	movedown_e(t_var *v);
void	movedown_v(t_var *v);
void	moveleft_c(t_var *v);
void	moveleft_e(t_var *v);
void	moveleft_v(t_var *v);
void	moveright_c(t_var *v);
void	moveright_e(t_var *v);
void	moveright_v(t_var *v);
void	add_exit_player(t_var *v);
void	check_door_open(t_var *v);
void	ft_display_map(t_game *game);
void	create_image_map(t_var *var);
void	ft_free(char **s, t_game *game);
void	extract_exit_position(t_game *game);
void	extract_player_position(t_game *game);
void	add_wall(t_var *v, size_t i, size_t j);
void	add_items(t_var *v, size_t i, size_t j);
void	add_ground(t_var *v, size_t i, size_t j);
void	extract_map_size(char *map, t_game *game);
void	extract_map_lines(char	*map, t_game *game);
void	add_vil(t_var *v, size_t i, size_t j);

#endif
