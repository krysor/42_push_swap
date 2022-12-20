/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_ra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:51:11 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 17:54:25 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_ra_iszero(t_list *tempra, t_list **a);
static int	ft_ra_iselse(t_list *tempra, t_list *tempa);

void	ft_get_nb_ra(t_list **ra, t_list **a)
{
	int		i;
	t_list	*tempa;
	t_list	*tempra;

	tempra = *ra;
	while (tempra)
	{
		i = 1;
		tempa = *a;
		while (tempa)
		{
			if (ft_ra_iszero(tempra, a))
			{
				*(int *)(tempra->content) = 0;
				break ;
			}
			if (ft_ra_iselse(tempra, tempa))
			{
				*(int *)(tempra->content) = i;
				break ;
			}
			i++;
			tempa = tempa->next;
		}
		tempra = tempra->next;
	}
}

static int	ft_ra_iszero(t_list *tempra, t_list **a)//split for readability
{
	if (ft_lstsize(*a) == 1 || (ft_issorted(a)
			&& (*(int *)(tempra->content) < *(int *)((*a)->content)
		|| *(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content)))
		|| (*(int *)(tempra->content) < *(int *)((*a)->content)
		&& *(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content)))
		return (1);
	return (0);
}

static int	ft_ra_iselse(t_list *tempra, t_list *tempa)//split for readability
{
	if (tempa->next != NULL
		&& ((*(int *)(tempa->content) < *(int *)(tempra->content)
		&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
		|| (*(int *)(tempa->content) > *(int *)((tempa->next)->content)
		&& ((*(int *)(tempra->content) < *(int *)(tempa->content)
		&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
		|| (*(int *)(tempra->content) > *(int *)(tempa->content)
		&& *(int *)(tempra->content) > *(int *)((tempa->next)->content))))))
		return (1);
	return (0);
}
