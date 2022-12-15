#include "push_swap.h"

//DELETE AT THE END:
static void		ft_putcontent_fd(void *content);

t_list	**ft_allis_init(t_list **lst);
t_list	*ft_nodedup(t_list *node);

void ft_solve_exit(t_list **a, t_list **b, char *result);

void ft_pushallbutx(t_list **src, t_list **dst, int x);

char	*ft_solve(t_list **a)
{
	char	*result;
	t_list	**b;
	
	result = ft_strempty();
	b = ft_lstinit();
	if (result == NULL || b == NULL)
		ft_solve_exit(a, b, result);
	ft_pushallbutx(a, b, 1);

	int i = 0;//delete later
	while (i == 0)//!ft_issorted(a))
	{
		if (!ft_putbest(a, b, result))
			ft_solve_exit(a, b, result);
		i++;
	}

	//printf("a___________________:\n");
	//ft_putlst_fd(a, 1);
	//printf("b___________________:\n");
	//ft_putlst_fd(b, 1);

	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	return (result);
}

void ft_pushallbutx(t_list **src, t_list **dst, int x)
{
	int	i;
	
	i = ft_lstsize(*src);
	if (x < 0)
		x = 0;
	while (i > x)
	{	
		ft_push(src, dst);
		i--;
	}
}

void ft_solve_exit(t_list **a, t_list **b, char *result)
{
	if (result != NULL)
		free(result);
	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	ft_putlst_fd(t_list **lst, int fd)//delete at the end
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
