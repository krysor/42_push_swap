#include "push_swap.h"

l_list **ft_parse(int argc, char *argv[]);
l_list **ft_lst_init(char **arr);
l_list **ft_lst_make(char **arr, l_list **lst);
l_list **ft_dup_check(l_list **lst);
void ft_freearr(char **arr);
void ft_putarr_fd(char **arr, int fd);
void ft_putpnt_fd(void *pnt);


int main(int argc, char *argv[])
{
    l_list	**inputs;
	//char	**result;

	if (argc <= 1)
    {
	    ft_putstr_fd("Error\n", 1);
		return (-1);
	}
    else if (argc >= 2)
    {
		inputs = ft_parse(argc, argv);
		if (inputs == NULL)
		{
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}

		//printer function to test the inputs
		//ft_putstr_fd("start of lstiter\n", 1);
		//ft_putlst_fd(inputs, 1);
		//ft_putstr_fd("end of lstiter\n", 1);

		//call the solver function
		//result = ft_solve(inputs);
		//if result != NULL
		// 	 print (result)
		//FREE inputs (with clear lst function)
		//FREE result (with whatever applicable)
	}
    return (1);
}

l_list **ft_parse(int argc, char *argv[])
{
	l_list	**lst;
	char 	**arr;

	if (argc == 2)
    {
        arr = ft_split(argv[1], ' ');
        if (arr == NULL || *arr == NULL)
			return (NULL);
    }
	else
		arr = argv + 1;	
	lst = ft_lst_init(arr);
	if (argc == 2)
		ft_freearr(arr);
	return (lst);
}

l_list **ft_lst_init(char **arr)
{
	long int	li;
	l_list		*lst;

	li = ft_atol(arr[0]);
	if (li == LONG_MIN)
		return (NULL);
	//printf("first elem: %li\n", li);
	lst = ft_lstnew((int)li);
	if (lst == NULL)
		return (NULL);
	printf("ft_lst_init just before return\n");
	return (ft_lst_make(arr, &lst));
}

l_list **ft_lst_make(char **arr, l_list **lst)
{
	long int	li;
	l_list		*temp;
	int			i;

	i = 1;
	printf("ft_lst_make at the top\n");
	while (arr[i] != NULL)
	{
		//printf("before seg or no\n");
		li = ft_atol(arr[i]);
		if (li == LONG_MIN)
		{
			ft_lstclear(lst);
			break ;
		}
		temp = ft_lstnew((int)li);
		if (temp == NULL)
		{
			ft_lstclear(lst);
			break ;
		}
		ft_lstadd_back(lst, temp);
		i++;
	}
	printf("before seg or no 1\n");
	if ((*lst)->next == NULL)
		return (lst);
	return (ft_dup_check(lst));
}

l_list **ft_dup_check(l_list **lst)
{
	l_list	*current;
	l_list	*temp;
	
	printf("hi!\n");
	current = *lst;
	temp = current->next;
	while (temp != NULL)
	{
		while (temp != NULL)
		{
			if (current->nb == temp->nb)
			{
				ft_lstclear(lst);
				return (NULL);
			}
			temp = temp->next;
		}
		current = current->next;
		temp = current->next;
	}
	return (lst);
}

void ft_freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

		/*
		lst = ft_arrtol(inputs);
		if (lst == NULL)
		{
			ft_putstr_fd("Error\n", 1);
			exit ();
		}
		*/


void ft_putarr_fd(char **arr, int fd)//delete at the end
{
	int	i;
	
	i = 0;
	while (arr[i] != NULL)
	{
		ft_putstr_fd(arr[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}

/*
void ft_putlst_fd(l_list **lst)//delete at the end
{	
	ft_putstr_fd("putpnt start:\n", 1);
	printf("%d", *(int *)pnt);
	//ft_putstr_fd(ft_itoa(*(int *)pnt), 1);
	ft_putstr_fd("\n", 1);
}
*/
/*
t_list	**ft_arrtol(char **inputs)
{
	t_list	*lst;
	int		content;

	if (ft_content == NULL)
		return (NULL);
	
	//get content candidate with modified atoi: think about return value in case of incorrect outcome + free everything else
	lst = ft_lstnew(content);//some atoi variation inside + put whole process in a loop
	
	
	
	return (&lst);
}
*/

//checks to perform on the input
//1. is it a properly formatted number: array to long long int / if not an int, return max or min long long int valeu
//2. is it an integer: / is it smaller than max int and larger than min int
//3. are there multiple occurences / iterate over the list for each element from left to right

/*
input/outputs
1. char array / u int array
2. u int array / int array
3. int array / int array
*/