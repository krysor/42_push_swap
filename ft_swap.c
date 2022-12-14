#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*temp;
	
	if (lst == NULL || *lst == NULL || ft_lstsize(*lst) == 1)
		return ;
	temp = *lst->next;
	*lst->next = (*lst->next)->next;
	temp->next = *lst;
	//finish this shit
}