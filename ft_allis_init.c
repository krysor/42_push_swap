//function: get LIS
//return value: t_list **LIS
/*
step 1: get all possible IS
		create a LIST to store all possible IS
			create a LIST to store the IS
		each CONTENT has address of the list with only one node
step 2: pick the IS that's the longest
		iterate over LIST with all IS and store the one that's currently the longest
		free all the rest
step 3: if more than 1, pick the first one
*/

//create a copy of my double list (using my function)
//append all possible double element IS for first element in the list

//repeat the same for all the others elements in the list
//keep repeating untill the IS list stops growing
//pick the longest list

//this one should try each element after the current element as the next one AND all the elements before it
t_list **ft_allis_init(t_list **lst)
{
	t_list	**lstoflst;
	t_list	*temp;
	//void	*address;
	t_list	*node;
	
	if (lst == NULL || *lst == NULL)
		return (NULL);
	lstoflst = (t_list **)malloc(sizeof(t_list *));
	if (lstoflst == NULL)
		return (NULL);
	temp = *lst;
	while (temp)
	{
		//create a node to hold address to first list
		node = ft_lstnew(&ft_nodedup(temp));//may need to allocate the pointer
		ft_lstadd_back(lstoflst, node);
		//ERROR exit condition + function

		//get a copy of the first lst node
		//create lst containing only one lst node
		//put address to that node as content


		//create nodes to hold addresses to (single) lists
	}
	return (lstoflst);


	//make a list just like every other
	//as content store the first node of each list to store
}

t_list	*ft_nodedup(t_list *node)
{
	t_list	*dup;
	void	*cont;
	
	if (node == NULL)
		return (NULL);
	dup = (t_list *)malloc(sizeof(t_list));
	if (dup == NULL)
		return (NULL);
	cont = ft_contdup(node->content);
	if (cont == NULL)
	{
		free (dup);
		return (NULL);
	}
	dup->content = cont;
	dup->next = NULL;
	return (dup);
}