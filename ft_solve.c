#include "push_swap.h"

//DELETE AT THE END:
static void		ft_putcontent_fd(void *content);

t_list	**ft_allis_init(t_list **lst);
t_list	*ft_nodedup(t_list *node);

void ft_solve_exit(t_list **a, t_list **b, char *result);
char	*ft_pushallbutxtob(t_list **src, t_list **dst, int x, char *result);

char	*ft_solve(t_list **a)
{
	char	*result;
	t_list	**b;
	
	result = ft_strempty();
	b = ft_lstinit();
	if (result == NULL || b == NULL)
		ft_solve_exit(a, b, result);
	if (ft_issorted(a))
	{
		free(b);
		return (result);
	}
	if (ft_iscis(a))
	{
		result = ft_cistosorted(a, result);
		if (!result)
			ft_solve_exit(a, b, result);
		ft_lstclear(a, (void *)free);
		ft_lstclear(b, (void *)free);
		free(b);
		return (result);
	}	

	result = ft_pushallbutxtob(a, b, 3, result);
	if (!result)
		ft_solve_exit(a, b, result);

	if (!ft_iscis(a))
		result = ft_swapsave(a, result, "sa\n\0");

	if (!result)
		ft_solve_exit(a, b, result);

	//int i = 0;//delete later
	while (ft_lstsize(*b) != 0)// && i < 4)//!ft_issorted(a)) && !ft_iscis(a)+ add the necessary conditions
	{
		result = ft_putbest(a, b, result); 
		if (!result)
			ft_solve_exit(a, b, result);
		//i++;
	}

	if (!ft_issorted(a))
		result = ft_cistosorted(a, result);

	if (!result)
		ft_solve_exit(a, b, result);

	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	free(b);
	return (result);
}

char	*ft_pushallbutxtob(t_list **src, t_list **dst, int x, char *result)
{
	int		i;
	char	*new_result;
	
	i = ft_lstsize(*src);
	if (x < 0)
		x = 0;
	new_result = result;
	while (i > x)
	{	
		new_result = ft_pushsave(src, dst, new_result, "pb\n\0");
		if (!new_result)
			return (NULL);
		i--;
	}
	return (new_result);
}

void ft_solve_exit(t_list **a, t_list **b, char *result)
{
	if (result != NULL)
		free(result);
	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	free(a);
	free(b);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	ft_putlst_fd(t_list **lst, int fd)//delete at the end
{	
	ft_putstr_fd("putlst start:\n", fd);
	ft_lstiter(*lst, (void *)ft_putcontent_fd);
	ft_putstr_fd("putlst end;\n", fd);
	ft_putstr_fd("_______________________\n", fd);
}

static void	ft_putcontent_fd(void *content)//delete at the end
{
	ft_putnbr_fd(*(int *)content, 1);
	ft_putchar_fd('\n', 1);
}
