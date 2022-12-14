#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_list	**input;
	char	*result;

	if (argc <= 1)
    {
	    ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	input = ft_parse(argc, argv);
	result = ft_solve(input);
	ft_putstr_fd(result, 1);
	ft_lstclear(input, (void *)free);
	free(input);
	if (result != NULL)
		free(result);
    return (1);
}
