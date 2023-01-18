/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:04:56 by rrebois           #+#    #+#             */
/*   Updated: 2022/12/19 11:31:12 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (unsigned char *)s1 + i && (unsigned char *)s2 + i)
	{
		if (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
			i++;
		else
			break ;
	}
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
