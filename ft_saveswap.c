/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:02:03 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 17:03:47 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL || ft_lstsize(*lst) <= 1)
		return ;
	temp = (*lst)->next;
	(*lst)->next = ((*lst)->next)->next;
	temp->next = *lst;
	*lst = temp;
}

char	*ft_saveswap(t_list **lst, char *result, char *str)
{
	char	*new_str;

	ft_swap(lst);
	new_str = ft_strjoin(result, str);
	free(result);
	if (!new_str)
		return (NULL);
	return (new_str);
}
