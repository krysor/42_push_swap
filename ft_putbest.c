#include "push_swap.h"

void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
void	ft_get_nb_rb(t_list **rb);

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
	ft_get_nb_rb(rb);
	printf("rb:________________\n");
	ft_putlst_fd(rb, 1);
	
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
	return (1);
}

void	ft_get_nb_rb(t_list **rb)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *rb;
	printf("halloo\n");
	while (!temp)
	{
		*(int *)(temp->content) = i;
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