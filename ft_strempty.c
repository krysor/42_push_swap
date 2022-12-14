#include "push_swap.h"

char	*ft_strempty(void)
{
	char	*result;
	result = malloc(sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	return (result);
}