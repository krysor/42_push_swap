#include "push_swap.h"

void	ft_push(t_list **dst, t_list **src)
{
	if (src == NULL || *src == NULL)
		return ;
	ft_lstaddfront(dst, *src);
	src++;
}