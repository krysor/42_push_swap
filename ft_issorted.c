#include "push_swap.h"

int	ft_issorted(t_list **lst)
{
	t_list *temp;
	
	if (ft_lstsize(*lst) <= 1)
		return (1);
	temp = *lst;
	while (temp->next)
	{
		if (*(int *)(temp->content) > *(int *)((temp->next)->content))
			return (0);
		temp = temp->next;	
	}
	return (1);
}

int	ft_iscis(t_list **lst)
{
	t_list	*temp;
	int		p;
	int		first;
	
	if (ft_lstsize(*lst) <= 1 || ft_issorted(lst))
		return (1);
	temp = *lst;
	first = *(int *)(temp->content);
	p = 1;
	while (temp->next)
	{
		if (*(int *)(temp->content) > *(int *)((temp->next)->content))
		{
			if (!p)
				return (0);
			p = 0;
		}
		temp = temp->next;	
	}
	if (first > *(int *)(temp->content))
		return (1);
	return (0);
}

char	*ft_cistosorted(t_list **lst, char *result)
{
	t_list	*temp;
	int		tie;

	temp = *lst;
	tie = 0;
	while (temp->next)
	{
		if (*(int *)(temp->content) > *(int *)((temp->next)->content))
			break ; 
		tie++;
		temp = temp->next;	
	}
	if (tie < ft_lstsize(*lst) / 2)
	{
		while (result != NULL && !ft_issorted(lst))
		{
			result = ft_rotatesave(lst, result, "ra\n\0");
			if (!result)
				return (NULL);
		}
	}	
	else
	{
		while (result != NULL && !ft_issorted(lst))
		{
			result = ft_revrotatesave(lst, result, "rra\n\0");
			if (!result)
				return (NULL);
		}	
	}
	return (result);
}
