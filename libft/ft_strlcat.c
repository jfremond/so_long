/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:12:09 by jfremond          #+#    #+#             */
/*   Updated: 2020/05/11 14:22:44 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	d_size;

	count = 0;
	while (dest[count] && count < size)
		count++;
	d_size = count;
	while (src[count - d_size] && count + 1 < size)
	{
		dest[count] = src[count - d_size];
		count++;
	}
	if (d_size < size)
		dest[count] = '\0';
	return (d_size + ft_strlen(src));
}
