#include "push_swap.h"

void	ft_push(t_list **src, t_list **dst)
{
	t_list	*temp;
	
	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, temp);
}

char	*ft_pushsave(t_list **src, t_list **dst, char *result, char *str)
{
	char *new_str;

	ft_push(src, dst);
	new_str = ft_strjoin(result, str);
	free(result);
	if (!new_str)
		return (NULL);
	return (new_str);
}