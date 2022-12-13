#include "push_swap.h"

//DELETE AT THE END:
static void		ft_putlst_fd(t_list **lst, int fd);
static void		ft_putcontent_fd(void *content);

char	*ft_solve(t_list **a)
{
	//if input is sorted already, print empty strign
	if (ft_issorted(a))
		return ("sorted\n");	
	//else, do the magic

	//this makes copy of a with second a after first a
	t_list **ring = ft_lstdouble(a);//add protection for NULL return in my final code
	printf("printing ring: \n");
	ft_putlst_fd(ring, 1);
	ft_lstclear(ring, (void *)free);
	free(ring);

	//do the LIS stuff

	//I'll need F returning LIS with its contents
	return ("unsorted\n");
}

/*
////my idea to LIS
//create a list of lists consisting of all the elements from my
t_list **ft_allis(t_list **lst)
{
	t_list	**lstoflst;
	t_list	*temp;
	
	//this one should try each element after the current element as the next one AND all the elements before it
	if (lst == NULL || *lst == NULL)
		return (NULL);
	lstoflst = (t_list **)malloc(sizeof(t_list *));
	if (lstoflst == NULL)
		return (NULL);
	temp = *lst;
	while (temp)
	{

	}


	//make a list just like every other
	//as content store the first node of each list to store
}
*/
//create a copy of my double list (using my function)
//append all possible double element IS for first element in the list

//repeat the same for all the others elements in the list
//keep repeating untill the IS list stops growing
//pick the longest list


//function: get LIS from list (in circular fashion)
//return value: 
/*
step 1: get all possible IS
		create a LIST to store all possible IS
			create a LIST to store the IS
step 2: pick the IS that's the longest
		iterate over LIST with all IS and store the one that's currently the longest
step 3: if more than 1, pick the first one


t_list **ft_lis(t_list **lst)
{
}

t_list ***ft_allis(t_list **lst)
{
}*/

static void	ft_putlst_fd(t_list **lst, int fd)//delete at the end
{	
	ft_putstr_fd("putlst start:\n", fd);
	ft_lstiter(*lst, (void *)ft_putcontent_fd);
	ft_putstr_fd("putlst end;\n", fd);
}

static void	ft_putcontent_fd(void *content)//delete at the end
{
	ft_putnbr_fd(*(int *)content, 1);
	ft_putchar_fd('\n', 1);
}
