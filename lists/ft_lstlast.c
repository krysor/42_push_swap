#include "lists.h"

l_list	*ft_lstlast(l_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return (NULL);
	else if ((*lst)->next == NULL)
		return (*lst);
	return ((*lst)->prev);
}