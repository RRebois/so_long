/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:10:14 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/02 11:26:14 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_putstr(char *s, unsigned int *ptr)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*ptr = *ptr + 6;
		return ;
	}
	write(1, s, ft_strlen(s));
	*ptr = *ptr + ft_strlen(s);
}
