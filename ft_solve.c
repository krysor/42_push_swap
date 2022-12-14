#include "push_swap.h"

//DELETE AT THE END:
static void		ft_putlst_fd(t_list **lst, int fd);
static void		ft_putcontent_fd(void *content);

t_list **ft_allis_init(t_list **lst);
t_list	*ft_nodedup(t_list *node);

char	*ft_solve(t_list **a)
{
	char	*result;
	t_list	**b;
	
	result = ft_strempty();//maybe put one \n in this
	b = ft_lstinit();
	if (result == NULL || b == NULL)
		ft_solve_exit(result, a, b);

	int	i = ft_lstsize(*a);
	while (i > 1)
	{	
		ft_push(a, b);
		i--;
	}

	ft_lstclear(a);
	ft_lstclear(b);
	return ();
}

void ft_solve_exit(char *result, t_list **a, t_list **b)
{
	if (result != NULL)
		free(result);
	ft_lstclear(a);
	ft_lstclear(b);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
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
