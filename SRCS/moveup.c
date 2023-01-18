/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:47:41 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 14:32:08 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	moveup_c(t_var *v)
{
	int		h;
	int		w;
	size_t	x;
	size_t	y;

	y = v->data.p.y;
	x = v->data.p.x - 1;
	if (v->data.map[x][y] == 'C')
		check_door_open(v);
	v->data.map[x][y] = 'P';
	v->data.map[x + 1][y] = '0';
	v->data.p.x -= 1;
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/ground/1.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, (x + 1) * h);
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/ground/1.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, x * h);
	if (x + 1 == v->data.e.x && y == v->data.e.y)
	{
		v->img.img = mlx_xpm_file_to_image(v->mlx, "img/EC.xpm", &w, &h);
		mlx_put_image_to_window(v->mlx, v->win, v->img.img, v->data.e.y * w, \
		v->data.e.x * h);
		v->data.map[x + 1][y] = 'E';
	}
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/P0.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, x * h);
}

void	moveup_e(t_var *v)
{
	int		h;
	int		w;
	size_t	x;
	size_t	y;

	y = v->data.p.y;
	x = v->data.p.x - 1;
	v->data.map[x + 1][y] = '0';
	v->data.p.x -= 1;
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/ground/1.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, (x + 1) * h);
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/P0.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, x * h);
	if (ft_strncmp(v->data.e.filename, "img/EO.xpm", \
	ft_strlen(v->data.e.filename)) == 0)
	{
		count_check(1);
		close_game(v);
	}
}
