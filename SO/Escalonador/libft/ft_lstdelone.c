/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:15:57 by hectfern          #+#    #+#             */
/*   Updated: 2022/07/17 00:29:35 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst)
		return ;
	next = lst->next;
	del(lst->content);
	lst->prev = NULL;
	free(lst);
	lst = next;
}
