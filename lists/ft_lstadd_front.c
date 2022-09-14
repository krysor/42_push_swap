#include "lists.h"

void	ft_lstadd_front(l_list **lst, l_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst != NULL)
	{
		if ((*lst)->next == NULL)
		{
			(*lst)->next = new;
			new->prev = *lst;
			new->next = *lst;
			(*lst)->prev = new;
		}
		else
		{
			ft_lstlast(lst)->next = new;
			new->prev = ft_lstlast(lst);
			new->next = *lst;
			(*lst)->prev = new;
		}
	}
	*lst = new;
}
