l_list	*ft_lstlast(l_list **lst)
{
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return (NULL);
	return ((*lst)->prev);
}