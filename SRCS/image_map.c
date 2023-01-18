/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:39:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 11:59:02 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	add_wall(t_var *v, size_t i, size_t j)
{
	int	w;
	int	h;

	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/wall/4.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, j * w, i * h);
}

void	add_ground(t_var *v, size_t i, size_t j)
{
	int	w;
	int	h;

	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/ground/1.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, j * w, i * h);
}

void	add_items(t_var *v, size_t i, size_t j)
{
	int	w;
	int	h;

	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/C.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, j * w, i * h);
}

void	add_exit_player(t_var *v)
{
	int	w;
	int	h;

	if (v->data.items == 0)
	{
		v->img.img = mlx_xpm_file_to_image(v->mlx, "img/EO.xpm", &w, &h);
		v->data.e.filename = "img/EO.xpm";
	}
	else
	{
		v->img.img = mlx_xpm_file_to_image(v->mlx, "img/EC.xpm", &w, &h);
		v->data.e.filename = "img/EC.xpm";
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, v->data.e.y * w, \
		v->data.e.x * h);
	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/P0.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, v->data.p.y * w, \
		v->data.p.x * h);
}

void	create_image_map(t_var *var)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (var->data.map[i] != '\0')
	{
		j = 0;
		while (var->data.map[i][j] != '\0')
		{
			if (var->data.map[i][j] == '1')
				add_wall(var, i, j);
			else
				add_ground(var, i, j);
			if (var->data.map[i][j] == 'C')
				add_items(var, i, j);
			j++;
		}
		i++;
	}
	add_exit_player(var);
}
