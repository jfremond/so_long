/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:24:00 by jfremond          #+#    #+#             */
/*   Updated: 2020/10/31 15:32:46 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*tmp;

	if (lst && *lst)
	{
		elem = *lst;
		*lst = NULL;
		while (elem)
		{
			tmp = elem->next;
			del(elem->content);
			free(elem);
			elem = tmp;
		}
	}
}
