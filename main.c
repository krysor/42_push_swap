#include "push_swap.h"

static t_list	**ft_parse(int argc, char *argv[]);
static t_list	**ft_atolst(char **arr, int	argc);
static void		ft_freearr(char **arr);
static void		ft_putarr_fd(char **arr, int fd);
static void		ft_putlst_fd(t_list **lst, int fd);
static void		ft_putcontent_fd(void *content);

int main(int argc, char *argv[])
{
    t_list	**input;
	//char	**result;

	if (argc <= 1)
    {
	    ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	input = ft_parse(argc, argv);
	/*	
	if (input == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	*/
	//result = ft_solve(input);		
	/*
	if result == NULL
	{		
		FREE input
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	*/
	//print result
	//FREE input (with clear lst function)
	ft_lstclear(input, (void *)free);
	//FREE result (with whatever applicable)
    return (1);
}


static t_list	**ft_parse(int argc, char *argv[])
{
	char	**arr;
	t_list	**lst;

	if (argc == 2)
    {
        arr = ft_split(argv[1], ' ');
        if (arr == NULL || *arr == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
    }
	else
		arr = argv + 1;
	printf("arr start:\n");
	ft_putarr_fd(arr, 1);//DELETE AT THE END
	printf("arr end;\n");
	lst = ft_atolst(arr, argc);
	ft_putlst_fd(lst, 1);//DELETE AT THE END
	if (argc == 2)
		ft_freearr(arr);
	return (lst);
}

static t_list	**ft_atolst(char **arr, int	argc)
{
	int			i;
	t_list		**lst;
	t_list		*node;
	void		*content;

	i = 0;
	lst = (t_list **)malloc(sizeof(t_list *));
	while (arr[i] != NULL)//simplify the list initiation
	{	
		content = ft_atopi(arr[i]);
		node = ft_lstnew(content);
		if (i == 0 && lst != NULL)
			*lst = node;
		if (i != 0)
			ft_lstadd_back(lst, node);
		if (content == NULL || node == NULL || ft_isdup(lst))
		{
			if (argc == 2)
				ft_freearr(arr);
			ft_lstclear(lst, (void *)free);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		i++;
	}
	return (lst);
}

static void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return;
	while (arr[i] != NULL)
		i++;
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

static void	ft_putarr_fd(char **arr, int fd)//delete at the end
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
