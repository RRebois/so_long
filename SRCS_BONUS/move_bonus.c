/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:46:05 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/18 13:12:19 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

void	key_left(t_var *v)
{
	if (v->data.map[v->data.p.x][v->data.p.y - 1] != '1')
		count_check(0, v);
	if (v->data.map[v->data.p.x][v->data.p.y - 1] == 'C' || \
	v->data.map[v->data.p.x][v->data.p.y - 1] == '0')
		moveleft_c(v);
	else if (v->data.map[v->data.p.x][v->data.p.y - 1] == 'E')
		moveleft_e(v);
	else if (v->data.map[v->data.p.x][v->data.p.y - 1] == 'V')
		moveleft_v(v);
}

void	key_down(t_var *v)
{
	if (v->data.map[v->data.p.x + 1][v->data.p.y] != '1')
		count_check(0, v);
	if (v->data.map[v->data.p.x + 1][v->data.p.y] == 'C' || \
	v->data.map[v->data.p.x + 1][v->data.p.y] == '0')
		movedown_c(v);
	else if (v->data.map[v->data.p.x + 1][v->data.p.y] == 'E')
		movedown_e(v);
	else if (v->data.map[v->data.p.x + 1][v->data.p.y] == 'V')
		movedown_v(v);
}

void	key_right(t_var *v)
{
	if (v->data.map[v->data.p.x][v->data.p.y + 1] != '1')
		count_check(0, v);
	if (v->data.map[v->data.p.x][v->data.p.y + 1] == 'C' || \
	v->data.map[v->data.p.x][v->data.p.y + 1] == '0')
		moveright_c(v);
	else if (v->data.map[v->data.p.x][v->data.p.y + 1] == 'E')
		moveright_e(v);
	else if (v->data.map[v->data.p.x][v->data.p.y + 1] == 'V')
		moveright_v(v);
}

void	key_up(t_var *v)
{
	if (v->data.map[v->data.p.x - 1][v->data.p.y] != '1')
		count_check(0, v);
	if (v->data.map[v->data.p.x - 1][v->data.p.y] == 'C' || \
	v->data.map[v->data.p.x - 1][v->data.p.y] == '0')
		moveup_c(v);
	else if (v->data.map[v->data.p.x - 1][v->data.p.y] == 'E')
		moveup_e(v);
	else if (v->data.map[v->data.p.x - 1][v->data.p.y] == 'V')
		moveup_v(v);
}
