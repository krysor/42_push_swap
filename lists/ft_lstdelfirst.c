#include "lists.h"

void	ft_lstdelfirst(l_list **lst)
{
	l_list	*temp;
	
	if (lst == NULL)
		return ;
	if (*lst == NULL || (*lst)->prev == NULL)
	{
		free (*lst);
		lst = NULL;
		return ;
	}
	if (ft_lstsize(lst) == 2)
	{
		*lst = (*lst)->next;
		free ((*lst)->next);
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		return ;
	}
	ft_lstlast(lst)->next = (*lst)->next;
	((*lst)->next)->prev = ft_lstlast(lst);
	temp = (*lst)->next;
	free (*lst);
	*lst = temp;
}