/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:17:03 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 11:24:21 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static int	check_items(t_game *game)
{
	size_t	i;
	int		player;
	int		exit;
	int		item;

	i = 0;
	player = 0;
	exit = 0;
	item = 0;
	while (game->mappy[i] != '\0')
	{
		if (game->mappy[i] == 'C')
			item++;
		if (game->mappy[i] == 'P')
			player++;
		if (game->mappy[i] == 'E')
			exit++;
		i++;
	}
	if (item < 1 || player != 1 || exit != 1)
		return (1);
	return (0);
}

static int	check_closed_map(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (i == 0 || i == g->height - 1)
			{
				if (g->map[i][j] != '1')
					return (ft_printf("Error\nMap must be wall \
surrounded.\n"), 1);
			}
			else
			{
				if ((g->map[i][0] != '1') || (g->map[i][g->width - 1] != '1'))
					return (ft_printf("Error\nMap must be wall \
surrounded.\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid_map(t_game *game)
{
	if (game->width + game->height < 8)
		return (ft_printf("Error\nMap too small.\n"), 1);
	if (check_closed_map(game) == 1)
		return (1);
	if (check_items(game) == 1)
	{
		ft_printf("Error\nMap must contain 1 exit, 1 starting point \
and at least 1 item.\n");
		return (1);
	}
	return (0);
}
