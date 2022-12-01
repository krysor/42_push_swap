#include "push_swap.h"

int	ft_isdup(t_list **lst)
{
	int	nb;
	int	count;
	t_list	*l;

	if (lst == NULL || *lst == NULL)
		return (1);
	nb = *(int *)(ft_lstlast(*lst)->content);
	count = 0;
	l = *lst;
	while (l != NULL)
	{
		if (*(int *)(l->content) == nb)
			count++;
		l = l->next;
	}
	if (count == 1)
		return (0);
	return (1);
}
