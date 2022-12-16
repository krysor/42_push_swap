#include "push_swap.h"

void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
void	ft_get_nb_rb(t_list **rb);
void	ft_get_nb_rrb(t_list **rrb);
void	ft_get_nb_ra(t_list **ra, t_list **a);

	//this is about ONE SINGLE MOVE
int ft_putbest(t_list **a, t_list **b, char *result)
{
	t_list	**ra;
	t_list	**rra;
	t_list	**rb;
	t_list	**rrb;

	ra = ft_lstdup(b);
	rra = ft_lstdup(b);
	rb = ft_lstdup(b);
	rrb = ft_lstdup(b);
	if (ra == NULL || rra == NULL || rb == NULL || rrb == NULL)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		return (0);
	}
	//calculate nb of ra in A for all elements in B
	
	
	//(void)b;
	(void)result;
	printf("a:____________________\n");
	ft_putlst_fd(a, 1);
	printf("ra before get_nb_ra:________________\n");
	ft_putlst_fd(ra, 1);
	ft_get_nb_ra(ra, a);
	printf("ra after get_nb_ra:________________\n");
	ft_putlst_fd(ra, 1);
	
	//calculate which should get put first
		//calculate how many instructions of each type for each
			//get the information
				//how many moves in a
				//how many moves in b
				//magic 2x2 table
			//calculate each information
		//choose the best one
			//iterate over data structure and save the current best choice
		//append the instructions to the instructions strings
			//possibly modify first if possible to optimize by 2 sides singel instruction moves
	//execute the best one
	ft_putbest_free(ra, rra, rb, rrb);
	return (1);
}

void	ft_get_nb_ra(t_list **ra, t_list **a)
{
	int	i;
	t_list *tempa;
	t_list *tempra;

	tempra = *ra;
	while (tempra)
	{
		i = 1;
		tempa = *a;
		while (tempa)
		{
			if (ft_lstsize(*a) == 1 || (ft_issorted(a) &&
				((*(int *)(tempra->content) < *(int *)((*a)->content))
				|| (*(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content))))
				|| ((*(int *)(tempra->content) < *(int *)((*a)->content))
					&& (*(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content))))
			{
				*(int *)(tempra->content) = 0;
				break ;
			}
			if ((tempa->next != NULL) && (*(int *)(tempa->content) < *(int *)(tempra->content))
				&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
			{//how tf is this correct for 7 1 5 10
				*(int *)(tempra->content) = i;
				break ;
			}
			if (tempa->next != NULL && *(int *)(tempa->content) > *(int *)((tempa->next)->content)
				&& ((*(int *)(tempra->content) < *(int *)(tempa->content)
				&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
				|| (*(int *)(tempra->content) > *(int *)(tempa->content)
				&& *(int *)(tempra->content) > *(int *)((tempa->next)->content))))
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
}

void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb)
{
	if (ra != NULL)
		ft_lstclear(ra, (void *)free);
	if (rra != NULL)
		ft_lstclear(rra, (void *)free);
	if (rb != NULL)
		ft_lstclear(rb, (void *)free);
	if (rrb != NULL)
		ft_lstclear(rrb, (void *)free);
}