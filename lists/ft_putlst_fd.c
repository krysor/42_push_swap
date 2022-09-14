#include "lists.h"

void	ft_putlst_fd(l_list **lst, int fd)
{
	l_list	*first_node;
	l_list	*last_node;
	
	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->prev == NULL)
	{
		ft_putnbr_fd((*lst)->nb, fd);
		ft_putchar_fd('\n', fd);
		return ;
	}
	first_node = *lst;
	last_node = ft_lstlast(lst);
	last_node->next = NULL;
	while (*lst != NULL)
	{
		ft_putnbr_fd((*lst)->nb, fd);
		ft_putchar_fd('\n', fd);
		*lst = (*lst)->next;
	}
	last_node->next = first_node;
	*lst = first_node;
}