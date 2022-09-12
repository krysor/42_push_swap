#include "push_swap.h"

void	ft_lstclear(l_list **lst)
{	
	l_list	*l;
	//l_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	if (ft_lstlast(lst) == NULL)
	{
		free (*lst);
		//free (lst);
		return ;
	}
	//temp = ft_lstlast(lst);
	while (l != NULL)
	{
		l = (*lst)->next;
		if (lst != NULL)
			free(lst);
		*lst = l;
	}

	l = *lst;
	while (l != NULL)
	{
		l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l;
	}

	lst = NULL;
}

//this function gives segfault
int	ft_lstsize(l_list **lst)
{
	int		size;
	l_list	*l;

	if (lst == NULL || *lst == NULL)
		return (0);
	size = 1;
	l = *lst;
	while (l->next != *lst)//segfault occurs in the while statement
	{
		size++;
		l = l->next;
		printf("before seg or no 2\n");
	}
	return (size);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))