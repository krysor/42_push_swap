#include "push_swap.h"

void	ft_push(t_list **src, t_list **dst)
{
	t_list	*temp;
	
	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	src = &((*src)->next);
	ft_lstadd_front(dst, temp);
}