/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:42:28 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 10:42:51 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	check_door_open(t_var *v)
{
	int	h;
	int	w;

	v->data.items--;
	if (v->data.items == 0)
	{
		v->img.img = mlx_xpm_file_to_image(v->mlx, "img/EO.xpm", &w, &h);
		mlx_put_image_to_window(v->mlx, v->win, v->img.img, v->data.e.y * w, \
		v->data.e.x * h);
		v->data.e.filename = "img/EO.xpm";
	}
}
