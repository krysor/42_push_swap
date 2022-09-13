#include "lists.h"

void	ft_lstclear(l_list **lst)
{	
	l_list	*l;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->prev == NULL)
	{
		free (*lst);
		lst = NULL;
		return ;
	}
	ft_lstlast(lst)->next = NULL;
	l = *lst;
	while (l != NULL)
	{
		l = (*lst)->next;
		if (lst != NULL)
			free(lst);
		*lst = l;
	}
	lst = NULL;
}