/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_rra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:50:24 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 17:50:49 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_nb_rra(t_list **rra, t_list **a)
{
	int		n;
	t_list	*temprra;

	ft_get_nb_ra(rra, a);
	n = ft_lstsize(*a);
	temprra = *rra;
	while (temprra)
	{
		if (*(int *)(temprra->content))
			*(int *)(temprra->content) = n - *(int *)(temprra->content);
		temprra = temprra->next;
	}
}
