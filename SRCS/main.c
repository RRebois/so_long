/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:42:57 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/20 12:38:36 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_display_map(t_game *game)
{
	t_var	var;
	void	*img_map;
	int		w;
	int		h;

	var.data = *game;
	var.mlx = mlx_init();
	img_map = mlx_xpm_file_to_image(var.mlx, "sprite/wall/4.xpm", &w, &h);
	var.img.img = img_map;
	var.win = mlx_new_window(var.mlx, game->width * 32, game->height * 32, \
	"so_long");
	create_image_map(&var);
	hooks(&var);
	mlx_loop(var.mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\nProgram takes exactly 1 .ber map argument.\n");
		return (1);
	}
	extract_map_size(av[1], &game);
	if (check_valid_map(&game) == 1 || check_valid_path(&game) == 1)
	{
		close_game_free(&game);
		return (1);
	}
	ft_display_map(&game);
	return (0);
}
