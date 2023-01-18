/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:38:11 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 12:41:08 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

static int	key_pressed(int a, t_var *v)
{
	if (a == ESC)
		close_game(v);
	else if (a == 0)
		key_left(v);
	else if (a == 1)
		key_down(v);
	else if (a == 2)
		key_right(v);
	else if (a == 13)
		key_up(v);
	return (0);
}

void	hooks(t_var *v)
{
	mlx_hook(v->win, ON_KEYDOWN, 1L << 0, key_pressed, v);
	mlx_hook(v->win, ON_DESTROY, 1L << 0, close_game, v);
}
