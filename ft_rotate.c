#include "push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*temp;
	
	if (lst == NULL || ft_lstsize(*lst) <= 1)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}