#include "lists.h"

//TRY TO REDO THE FUNCTION WITH RETURN TYPE

l_list	**ft_lstdelfirst(l_list **lst)
{
	l_list	*temp;
	l_list	**res;
	
	if (lst == NULL)
		return (lst);
	if (*lst == NULL || (*lst)->prev == NULL)
	{
		free (*lst);
		*lst = NULL;
		return (lst);
	}
	if (ft_lstsize(lst) == 2)
	{
		printf("am i here\n");
		ft_putlst_fd(lst, 1);
		/*
		(*lst)->nb = ((*lst)->next)->nb;
		(*lst)->prev = NULL;
		free ((*lst)->next);
		(*lst)->next = NULL;
		*/
		((*lst)->next)->next = NULL;
		((*lst)->next)->prev = NULL;
		res = &((*lst)->next);
		free (*lst);
		lst = NULL;
		ft_putlst_fd(lst, 1);
		printf("put ding\n");
		return (res);
	}
	ft_lstlast(lst)->next = (*lst)->next;
	((*lst)->next)->prev = ft_lstlast(lst);
	temp = (*lst)->next;
	free (*lst);
	*lst = temp;
	return (lst);
}


/*
void	ft_lstdelfirst(l_list **lst)
{
	l_list	*temp;
	
	if (lst == NULL)
		return ;
	if (*lst == NULL || (*lst)->prev == NULL)
	{
		free (*lst);
		*lst = NULL;
		return ;
	}
	if (ft_lstsize(lst) == 2)
	{
		printf("putlst before mod\n");
		ft_putlst_fd(lst, 1);
		//printf("am i here\n");
		//change first list element into second one and delete/free the second one
		//temp = (*lst)->next;
		(*lst)->nb = ((*lst)->next)->nb;
		(*lst)->prev = NULL;
		free ((*lst)->next);
		(*lst)->next = NULL;
		//printf("put ding\n");
		printf("putlst after mod\n");
		lst++;
		ft_putlst_fd(lst, 1);
		return ;
	}
	ft_lstlast(lst)->next = (*lst)->next;
	((*lst)->next)->prev = ft_lstlast(lst);
	temp = (*lst)->next;
	free (*lst);
	*lst = temp;
}
*/