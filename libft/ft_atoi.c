/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:20:04 by jfremond          #+#    #+#             */
/*   Updated: 2020/10/09 16:12:58 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*s == ' ' || *s == '\f' || *s == '\n'
		|| *s == '\r' || *s == '\t' || *s == '\v')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		result *= 10;
		result += *s - '0';
		s++;
	}
	return (result * sign);
}
