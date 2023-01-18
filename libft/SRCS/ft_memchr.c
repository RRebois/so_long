/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:16:53 by rrebois           #+#    #+#             */
/*   Updated: 2022/12/19 11:31:08 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s) == (unsigned char)c)
		{
			s = &s[i];
			return ((void *)s);
		}
		i++;
	}
	if (c == 0 && *(unsigned char *)(s) == '\0' && i < n)
	{
		s = &s[i];
		return ((void *)s);
	}
	return (NULL);
}
