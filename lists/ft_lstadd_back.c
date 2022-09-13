#include "lists.h"

//not working properly for an empty list
void	ft_lstadd_back(l_list **lst, l_list *new)
{
	if (lst == NULL)
	{
		lst = &new;
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	if ((*lst)->prev == NULL)
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
 