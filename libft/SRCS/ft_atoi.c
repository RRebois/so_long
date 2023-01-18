/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:26:11 by rrebois           #+#    #+#             */
/*   Updated: 2022/12/19 11:30:04 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static int	ft_check(int value, int sign)
{
	if ((value * sign) < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == 45)
			sign *= -1;
		if (str[i] == 43 || str[i] == 45)
			i++;
		while (str[i] >= 48 && str[i] <= 57)
		{
			if (value != value * 10 / 10)
				return (ft_check(value, sign));
			value = value * 10 + (str[i] - '0');
			i++;
		}
		return (sign * value);
	}
	return (0);
}
