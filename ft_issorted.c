#include "push_swap.h"

int	ft_issorted(t_list **lst)
{
	t_list *temp;
	
	if (ft_lstsize(*lst) <= 1)
		return (1);
	temp = *lst;
	while (temp->next)
	{
		if (*(int *)(temp->content) > *(int *)((temp->next)->content))
			return (0);
		temp = temp->next;	
	}
	return (1);
}