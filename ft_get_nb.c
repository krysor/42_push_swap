#include "push_swap.h"

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

int	ft_ra_iszero(t_list *tempra, t_list **a)//split for readability
{
	if (ft_lstsize(*a) == 1 || (ft_issorted(a) &&
		(*(int *)(tempra->content) < *(int *)((*a)->content)
		|| *(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content)))
		|| (*(int *)(tempra->content) < *(int *)((*a)->content)
		&& *(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content)))
		return (1);
	return (0);
}

int	ft_ra_iselse(t_list *tempra, t_list *tempa)//split for readability
{
	if (tempa->next != NULL && ((*(int *)(tempa->content) < *(int *)(tempra->content)
		&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
		|| (*(int *)(tempa->content) > *(int *)((tempa->next)->content)
		&& ((*(int *)(tempra->content) < *(int *)(tempa->content)
		&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
		|| (*(int *)(tempra->content) > *(int *)(tempa->content)
		&& *(int *)(tempra->content) > *(int *)((tempa->next)->content))))))
		return (1);
	return (0);
}

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

void	ft_get_nb_rrb(t_list **rrb)
{
	t_list	*temp;
	int		i;

	i = ft_lstsize(*rrb);
	temp = *rrb;
	while (temp)
	{
		*(int *)(temp->content) = i;
		i--;
		temp = temp->next;
	}
	*(int *)((*rrb)->content) = 0;
}