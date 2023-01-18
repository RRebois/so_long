/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:14:20 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 15:06:49 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

static void	text(int i, int count)
{
	if (i == 2)
		ft_printf("A monster killed you.\n");
	else
		ft_printf("Congratulations! You finished the game in %d moves\n", count);
}

void	count_check(int i, t_var *v)
{
	static int	count;
	int			h;
	int			w;

	v->img.img = mlx_xpm_file_to_image(v->mlx, "img/bh.xpm", &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, \
		v->data.height * h);
	if (i == 0)
	{
		count++;
		if (count == 1)
		{
			ft_printf("%d move\n", count);
			mlx_string_put(v->mlx, v->win, 10, (v->data.height + 1) * 31, \
			0xFFFFFFFF, ft_itoa(count));
		}
		else
		{
			ft_printf("%d moves\n", count);
			mlx_string_put(v->mlx, v->win, 10, (v->data.height + 1) * 31, \
			0xFFFFFFFF, ft_itoa(count));
		}
	}
	else
		text(i, count);
}
