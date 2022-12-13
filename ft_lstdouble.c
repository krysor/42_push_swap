#include "push_swap.h"

void	ft_lstfullclear(t_list **lst);
t_list **ft_lstcat(t_list **lst1, t_list **lst2);

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