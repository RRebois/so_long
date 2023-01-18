/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:52:56 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 10:20:15 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	extract_player_position(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->p.x = i;
				game->p.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	extract_exit_position(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	game->items = 0;
	while (game->map[i] != '\0')
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
			{
				game->e.x = i;
				game->e.y = j;
			}
			if (game->map[i][j] == 'C')
				game->items++;
			j++;
		}
		i++;
	}
	extract_player_position(game);
}

void	extract_map_lines(char	*map, t_game *game)
{
	char	*line;
	size_t	i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit (1);
	line = get_next_line(fd);
	game->mappy = (char *)malloc(sizeof(char));
	if (game->mappy == NULL)
		exit (1);
	game->mappy[0] = '\0';
	game->mappy = ft_strjoin_gnl(game->mappy, line);
	while (++i < game->height)
	{
		free(line);
		line = get_next_line(fd);
		game->mappy = ft_strjoin_gnl(game->mappy, line);
	}
	free (line);
	if (game->mappy == NULL)
		exit (1);
	game->map = ft_split(game->mappy, '\n');
	extract_exit_position(game);
}

void	extract_map_size(char *map, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit (1);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	game->height = 0;
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(fd);
		if (line != NULL && game->width != (ft_strlen(line) - 1))
		{
			ft_printf("Error\nMap must be rectangular.\n");
			exit (1);
		}
	}
	free(line);
	if (close(fd) == -1)
		exit(1);
	extract_map_lines(map, game);
}
