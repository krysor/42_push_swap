void	ft_lstadd_front(l_list **lst, l_list *new)
{
	if (new == NULL)
		return ;
	if (lst != NULL)
	{
		if ((*lst)->next == NULL)
		{
			(*lst)->next = new;
			new->prev = *lst;
			new->next = *lst;
			(*lst)->prev = new;
		}
		else
		{
			ft_lstlast(lst)->next = new;
			new->prev = ft_lstlast(lst);
			new->next = *lst;
			(*lst)->prev = new;
		}
	}
	*lst = new;
}

/*
void	ft_lstadd_front(l_list **lst, l_list *new)
{
	if (new == NULL)
		return ;
	
	//case 1: 0 elements
	if (lst == NULL)
	*lst = new;

	//case 2: 1 element
	else if (lst != NULL && (*lst)->next == NULL)
	{
		(*lst)->next = new;
		new->prev = *lst;
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}

	//case 3: n elements
	else
	{
		ft_lstlast(lst)->next = new;
		new->prev = ft_lstlast(lst);
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
}
*/
