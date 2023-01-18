/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:14:20 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 12:43:53 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	count_check(int i)
{
	static int	count;

	if (i == 0)
	{
		count++;
		if (count == 1)
			ft_printf("%d move\n", count);
		else
			ft_printf("%d moves\n", count);
	}
	else
		ft_printf("Congratulations! You finished the game in %d moves\n", count);
}
