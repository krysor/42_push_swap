#include "push_swap.h"

t_list **ft_lstinit(void)
{
	t_list	**lst;
	
	lst = (t_list **)malloc(sizeof(t_list *));
	if (lst != NULL)
		*lst = NULL;
	return (lst);
}