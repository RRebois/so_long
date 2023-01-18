/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveleft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:47:41 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 14:32:00 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	moveleft_c(t_var *v)
{
	int		h;
	int		w;
	size_t	x;
	size_t	y;

	y = v->data.p.y - 1;
	x = v->data.p.x;
	if (v->data.map[x][y] == 'C')
		check_door_open(v);
	v->data.map[x][y] = 'P';
	v->data.map[x][y + 1] = '0';
	v->data.p.y -= 1;
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/ground/1.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, (y + 1) * w, x * h);
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/ground/1.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, x * h);
	if (x == v->data.e.x && y + 1 == v->data.e.y)
	{
		v->img.img = mlx_xpm_file_to_image(v->mlx, "img/EC.xpm", &w, &h);
		mlx_put_image_to_window(v->mlx, v->win, v->img.img, v->data.e.y * w, \
		v->data.e.x * h);
		v->data.map[x][y + 1] = 'E';
	}
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/P0.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, x * h);
}

void	moveleft_e(t_var *v)
{
	int		h;
	int		w;
	size_t	x;
	size_t	y;

	y = v->data.p.y - 1;
	x = v->data.p.x;
	v->data.map[x][y + 1] = '0';
	v->data.p.y -= 1;
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/ground/1.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, (y + 1) * w, x * h);
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/P0.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, y * w, x * h);
	if (ft_strncmp(v->data.e.filename, "img/EO.xpm", \
	ft_strlen(v->data.e.filename)) == 0)
	{
		count_check(1);
		close_game(v);
	}
}
