/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:28:21 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/20 12:36:04 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	close_game(t_var *v)
{
	size_t	i;

	i = 0;
	while (i < v->data.height)
	{
		free(v->data.map[i]);
		v->data.map[i] = NULL;
		i++;
	}
	free(v->data.map);
	v->data.map = NULL;
	free(v->data.mappy);
	mlx_destroy_image(v->mlx, v->img.img);
	mlx_destroy_window(v->mlx, v->win);
	exit (1);
}

void	close_game_free(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
	free(game->mappy);
}
