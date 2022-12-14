#include "push_swap.h"

void	ft_revrotate(t_list **lst)
{
	t_list	*old_last;
	t_list	*new_last;
	int		size;
	
	if (lst == NULL || ft_lstsize(*lst) <= 1)
		return ;
	old_last = ft_lstlast(*lst);
	size = ft_lstsize(*lst);
	new_last = *lst;
	while (size > 2)
	{
		new_last = new_last->next;
		size--;
	}
	new_last->next = NULL;
	ft_lstadd_front(lst, old_last);
}