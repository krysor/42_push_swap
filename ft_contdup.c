#include "push_swap.h"

void *ft_contdup(void *content)
{
	int	*dup;

	if (content == NULL)
		return (NULL);
	dup = malloc(sizeof(content));
	if (dup == NULL)
		return (NULL);
	*dup = *(int *)content;
	return (dup);
}