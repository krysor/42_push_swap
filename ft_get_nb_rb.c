/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_rb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:49:55 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 17:50:16 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_nb_rb(t_list **rb)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *rb;
	while (temp)
	{
		*(int *)(temp->content) = i;
		i++;
		temp = temp->next;
	}
}
