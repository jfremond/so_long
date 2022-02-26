/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:11:46 by jfremond          #+#    #+#             */
/*   Updated: 2020/05/04 11:40:26 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	unsigned const char	*ptr_s;

	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned const char *)src;
	if (!dest && !src)
		return (NULL);
	if (src <= dest)
		while (n--)
			ptr_d[n] = ptr_s[n];
	else
		ft_memcpy(dest, src, n);
	return ((void *)ptr_d);
}
