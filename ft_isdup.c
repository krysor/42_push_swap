#include "push_swap.h"

int	ft_isdup(t_list **lst)
{
	int		nb;
	int		count;

	if (lst == NULL || *lst == NULL)
		return (1);
	nb = *(int *)(ft_lstlast(*lst)->content);
	count = 0;	
	while (*lst != NULL)
	{
		if (*(int *)((*lst)->content) == nb)
			count++;
		*lst = (*lst)->next;
	}
	if (count == 1)
		return (0);
	return (1);
}

