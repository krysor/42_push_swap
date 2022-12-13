#include "push_swap.h"

char	*ft_solve(t_list **input);
int		ft_issorted(t_list **lst);

void 	*ft_contdup(void *content);
t_list 	**ft_lstdup(t_list **lst);

t_list	**ft_lstdouble(t_list **lst);
void	ft_lstfullclear(t_list **lst);
t_list **ft_lstcat(t_list **lst1, t_list **lst2);


//DELETE AT THE END:
static void		ft_putlst_fd(t_list **lst, int fd);
static void		ft_putcontent_fd(void *content);

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

t_list **ft_lstdouble(t_list **lst)
{
	t_list	**lst1;
	t_list	**lst2;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	lst1 = ft_lstdup(lst);
	lst2 = ft_lstdup(lst);
	if (lst1 == NULL || lst2 == NULL)
	{
		ft_lstfullclear(lst1);
		ft_lstfullclear(lst2);
		return (NULL);
	}
	lst1 = ft_lstcat(lst1, lst2);
	free(lst2);
	return (lst1);
}

void ft_lstfullclear(t_list **lst)
{
	int p;
	
	p = 1;
	if (lst == NULL)
		p = 0;
	ft_lstclear(lst, (void *)free);
	if (p)
		free (lst);
}

t_list **ft_lstcat(t_list **lst1, t_list **lst2)
{
	if (lst1 == NULL || *lst1 == NULL
		|| lst2 == NULL || *lst2 == NULL)
		return (NULL);
	ft_lstlast(*lst1)->next = *lst2;
	return (lst1);
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

t_list **ft_lstdup(t_list **lst)
{
	t_list	**dup;
	t_list	*temp;
	void	*content;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	dup = (t_list **)malloc(sizeof(t_list *));
	if (dup == NULL)
		return (NULL);
	*dup = NULL;
	temp = *lst;
	while (temp != NULL)
	{
		content = ft_contdup(temp->content);
		ft_lstadd_back(dup, ft_lstnew(content));
		if (content == NULL || content != ft_lstlast(*dup)->content) 
		{
			ft_lstclear(dup, (void *)free);
			free(content);
			free(dup);
			return (NULL);
		}
		temp = temp->next;
	}
	return (dup);
}

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
