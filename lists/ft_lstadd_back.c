#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
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
