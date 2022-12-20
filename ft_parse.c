#include "push_swap.h"

static t_list	**ft_atolst(char **arr, int	argc);
static void		ft_atolst_exit(char **arr, int	argc, t_list **lst, void *content);
static int		ft_atolst_iserr(t_list **lst, int i);
static void		ft_freearr(char **arr);

t_list	**ft_parse(int argc, char *argv[])
{
	char	**arr;
	t_list	**lst;

	if (argc == 2)
    {
        arr = ft_split(argv[1], ' ');
        if (arr == NULL || *arr == NULL)
		{
			if (*arr == NULL)
				ft_freearr(arr);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
    }
	else
		arr = argv + 1;
	lst = ft_atolst(arr, argc);
	if (argc == 2)
		ft_freearr(arr);
	return (lst);
}

static t_list	**ft_atolst(char **arr, int	argc)
{
	int		i;
	t_list	**lst;
	void	*content;

	i = 0;
	lst = ft_lstinit();
	while (arr[i] != NULL)
	{	
		if (lst != NULL)
		{
			content = ft_atopi(arr[i]);
			ft_lstadd_back(lst, ft_lstnew(content));
		}
		if (ft_atolst_iserr(lst, i))
			ft_atolst_exit(arr, argc, lst, content);
		i++;
	}
	return (lst);
}

static int	ft_atolst_iserr(t_list **lst, int i)
{
	if (lst == NULL || ft_lstsize(*lst) != i + 1
		|| ft_lstlast(*lst)->content == NULL || ft_isdup(lst))
		return (1);
	return (0);
}

static void ft_atolst_exit(char **arr, int	argc, t_list **lst, void *content)
{
	if (argc == 2)
		ft_freearr(arr);
	if (content != NULL && *(int *)(ft_lstlast(*lst)->content) != *(int *)content)
		free(content);
	ft_lstclear(lst, (void *)free);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return;
	if (arr[i] != NULL)
	{
		while (arr[i] != NULL)
			i++;
		while (i >= 0)
			free(arr[i--]);
	}
	free(arr);
}

/*
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
}*/
