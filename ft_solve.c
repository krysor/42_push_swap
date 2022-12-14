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

	//do the LIS stuff

	//I'll need F returning LIS with its contents
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
