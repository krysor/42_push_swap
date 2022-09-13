#include "lists.h"

l_list	*ft_lstnew(int nb)
{
	l_list	*lst;

	lst = (l_list *)malloc(sizeof(l_list));
	if (lst == NULL)
		return (NULL);
	lst->nb = nb;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}