#include "push_swap.h"

void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
void	ft_get_nb_rb(t_list **rb);
void	ft_get_nb_rrb(t_list **rrb);

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
	
	
	(void)a;
	(void)result;
	printf("rb before get_nb_rb:________________\n");
	ft_putlst_fd(rb, 1);
	ft_get_nb_rb(rb);
	printf("rb after get_nb_rb:________________\n");
	ft_putlst_fd(rb, 1);

	printf("rrb before get_nb_rrb:________________\n");
	ft_putlst_fd(rrb, 1);
	ft_get_nb_rrb(rrb);
	printf("rrb after get_nb_rrb:________________\n");
	ft_putlst_fd(rrb, 1);
	
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
		i = 0;
		tempa = *a;
		while (tempa)
		{
			if (ft_lstsize(*a) == 1)//special case if only 1 element in a
			{
				*(int *)(tempra->content) = i;
				break ;
			}
			else if (tempra < *(int *)((*tempa)->content))
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

*(int *)(tempra->content) = i;

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