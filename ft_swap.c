#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*temp;
	
	if (lst == NULL || ft_lstsize(*lst) <= 1)
		return ;
	temp = (*lst)->next;
	(*lst)->next = ((*lst)->next)->next;
	temp->next = *lst;
	*lst = temp;
}

char	*ft_swapsave(t_list **lst, char *result, char *str)
{
	char *new_str;

	ft_swap(lst);
	new_str = ft_strjoin(result, str);
	free(result);
	if (!new_str)
		return (NULL);
	return (new_str);
}