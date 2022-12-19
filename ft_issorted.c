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
	
	if (ft_lstsize(*lst) <= 1)
		return (1);
	temp = *lst;
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
	return (1);
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
		//printf("here?____________________\n");
		ft_putlst_fd(lst, 1);
		while (result != NULL && !ft_issorted(lst))//this one loops because the sorting doesnt work properly
		{
			result = ft_rotatesave(lst, result, "ra\n\0");
			//printf("loop?____________________\n");
		}
	}	
	else
	{
		while (result != NULL && !ft_issorted(lst))
			result = ft_revrotatesave(lst, result, "rra\n\0");
	}
	return (result);
}
