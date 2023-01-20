/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:07:47 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/20 10:07:49 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

void	ft_free_map(char **s, size_t a)
{
	size_t	i;

	i = 0;
	while (i < a)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

static void	spread_al(char **s, size_t i, size_t j)
{
	if (s[i][j] == '1' || s[i][j] == 'A' || s[i][j] == 'V')
		return ;
	else
	{
		s[i][j] = 'A';
		spread_al(s, i + 1, j);
		spread_al(s, i - 1, j);
		spread_al(s, i, j + 1);
		spread_al(s, i, j - 1);
	}
}

static int	control_al(char **s, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == 'P' || s[i][j] == 'E' || s[i][j] == 'C')
			{
				return (ft_printf("Error\nThis map has no valid path.\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static char	**ft_copy(char **s, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		s[i] = (char *)malloc(sizeof(char) * (game->width + 1));
		if (s[i] == NULL)
			return (ft_free_map(s, i), NULL);
		while (game->map[i][j] != '\0')
		{
			s[i][j] = game->map[i][j];
			j++;
		}
		s[i][j] = '\0';
		i++;
	}
	s[i] = 0;
	return (s);
}

int	check_valid_path(t_game *game)
{
	char	**s;

	s = (char **)malloc(sizeof(*s) * (game->height + 1));
	if (s == NULL)
		return (1);
	s = ft_copy(s, game);
	spread_al(s, game->p.x, game->p.y);
	if (control_al(s, game) == 1)
		return (ft_free_map(s, game->height), 1);
	return (ft_free_map(s, game->height), 0);
}
