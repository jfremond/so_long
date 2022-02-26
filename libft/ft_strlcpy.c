/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:17:16 by jfremond          #+#    #+#             */
/*   Updated: 2020/05/11 14:27:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	f_size;

	count = 0;
	f_size = 0;
	if (!dest)
		return (0);
	while (src[f_size])
		f_size++;
	if (!size)
		return (f_size);
	while (src[count] && count + 1 < size)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (f_size);
}
