#include "push_swap.h"

//DELETE AT THE END:
static void		ft_putlst_fd(t_list **lst, int fd);
static void		ft_putcontent_fd(void *content);

t_list **ft_allis_init(t_list **lst);
t_list	*ft_nodedup(t_list *node);

char	*ft_solve(t_list **a)
{
	//if input is sorted already, print empty strign
	if (ft_issorted(a))
		return ("sorted\n");	
	//else, do the magic


	printf("print a before\n");
	ft_putlst_fd(a, 1);
	t_list **b = ft_lstdup(a);
	printf("print b before\n");
	ft_putlst_fd(a, 1);

	ft_push(b, a);
	
	printf("print a after\n");
	ft_putlst_fd(a, 1);
	printf("print b after\n");
	ft_putlst_fd(a, 1);

	
	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);

	return ("unsorted\n");
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
