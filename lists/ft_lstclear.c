#include "lists.h"

void	ft_lstclear(l_list **lst)
{	
	if (lst == NULL)
		return ;
	while (lst != NULL && *lst != NULL)
		ft_lstdelfirst(lst);
}
