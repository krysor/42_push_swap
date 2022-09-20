#include "lists.h"

int	ft_lstsize(l_list **lst)
{
	int		size;
	l_list	*first_node;

	if (lst == NULL || *lst == NULL)
		return (0);
	size = 1;
	first_node = *lst;
	if ((*lst)->next == NULL)
		return (size);
	ft_lstlast(lst)->next = NULL;
	while ((*lst)->next != NULL)
	{
		size++;
		*lst = (*lst)->next;//prolly needs to use a temp var cause otherwise the real address gets changed as well
	}
	ft_lstlast(lst)->next = first_node;
	*lst = first_node;
	return (size);
}
