#include "lists.h"

int	ft_lstsize(l_list **lst)
{
	int		size;
	l_list	*first_node;

	if (lst == NULL || *lst == NULL)
		return (0);
	size = 1;
	first_node = *lst;
	if (ft_lstlast(lst)->next == NULL)
		return (size);
	ft_lstlast(lst)->next = NULL;
	while ((*lst)->next != NULL)
	{
		size++;
		*lst = (*lst)->next;
	}
	ft_lstlast(lst)->next = first_node;
	return (size);
}
