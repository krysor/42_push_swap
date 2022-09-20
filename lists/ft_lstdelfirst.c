#include "lists.h"

void	ft_lstdelfirst(l_list **lst)
{
	l_list	*temp;
	
	if (lst == NULL)
		return ;
	if (*lst == NULL || (*lst)->prev == NULL)
	{
		free (*lst);
		*lst = NULL;
		return ;
	}
	if (ft_lstsize(lst) == 2)
	{
		(*lst)->nb = ((*lst)->next)->nb;
		(*lst)->prev = NULL;
		free ((*lst)->next);
		(*lst)->next = NULL;
		return ;
	}
	ft_lstlast(lst)->next = (*lst)->next;
	((*lst)->next)->prev = ft_lstlast(lst);
	temp = (*lst)->next;
	free (*lst);
	*lst = temp;
}

/*	THIS ONE USES RETURN TYPE **
l_list	**ft_lstdelfirst(l_list **lst)
{
	l_list	*temp;
	l_list	**res;
	
	if (lst == NULL)
		return (lst);
	if (*lst == NULL || (*lst)->prev == NULL)
	{
		free (*lst);
		*lst = NULL;
		return (lst);
	}
	if (ft_lstsize(lst) == 2)
	{
		((*lst)->next)->next = NULL;
		((*lst)->next)->prev = NULL;
		res = &((*lst)->next);
		free (*lst);
		lst = NULL;
		return (res);
	}
	ft_lstlast(lst)->next = (*lst)->next;
	((*lst)->next)->prev = ft_lstlast(lst);
	temp = (*lst)->next;
	free (*lst);
	*lst = temp;
	return (lst);
}
*/