#include "push_swap.h"

char	*ft_solve(t_list **input);
int		ft_issorted(t_list **lst);

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
	//FREE input (with clear lst function)
	ft_lstclear(input, (void *)free);
	free(input);
	//if (result != NULL)
	//	free (result);
    return (1);
}

char	*ft_solve(t_list **a)
{
	//if input is sorted already, print empty strign
	if (ft_issorted(a))
		return ("sorted\n");	
	//else, do the magic

	//I'll need F returning LIS with its contents
	return ("unsorted\n");
}

int	ft_issorted(t_list **lst)
{
	t_list *temp;
	
	if (ft_lstsize(*lst) == 1)
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

//function: get LIS from list (in circular fashion)
//return value: 
/*
step 1: get all possible IS
		create a LIST to store all possible IS
			create a LIST to store the IS
step 2: pick the IS that's the longest
		iterate over LIST with all IS and store the one that's currently the longest
step 3: if more than 1, pick the first one
*/

t_list **ft_lis(t_list **lst)
{

}

t_list ***ft_allis(t_list **lst)
{
	//COPY LST and put 2 after each other
}

t_list ***ft_is(t_list **lst)
{
	//this one should try each element after the current element as the next one AND all the elements before it

}