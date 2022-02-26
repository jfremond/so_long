/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:25:45 by jfremond          #+#    #+#             */
/*   Updated: 2020/04/29 17:27:49 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;

	if (n > 0)
	{
		i = -1;
		ptr_s = (unsigned char *)s;
		while (++i < n)
			ptr_s[i] = 0;
	}
}
