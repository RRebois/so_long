/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_extra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:48:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 14:52:16 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

void	add_vil(t_var *v, size_t i, size_t j)
{
	int		w;
	int		h;
	char	*file;
	char	*number;
	char	*ext;

	number = ft_itoa(rand() % 26);
	ext = ft_strjoin(number, ".xpm");
	file = ft_strjoin("img/vil/", ext);
	v->img.img = mlx_xpm_file_to_image(v->mlx, file, &w, &h);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, j * w, i * h);
	free(file);
	file = NULL;
	free(number);
	number = NULL;
	free(ext);
	ext = NULL;
}
