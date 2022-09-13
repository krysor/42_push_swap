#include "lists.h"
#include <stdio.h>

int	main(void)
{
	l_list	**lst;
	l_list	*node;
	//int		i;


	//empty list check
	lst = NULL;
	printf("Zero elements checks:\n");

	printf("	ft_putlst_fd\n");
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	printf("	ft_lstdelfirst\n");
	ft_lstdelfirst(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	printf("	ft_lstclear\n");
	ft_lstclear(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	printf("	ft_lstlast\n");
	(void)ft_lstlast(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	printf("	ft_lstsize\n");
	printf("		size = %d\n", ft_lstsize(lst));
	printf("		Passed\n");

	//test add back: with both delfirst and lstclear
	lst = NULL;
	printf("	ft_lstnew and ft_lstadd_back\n");
	ft_lstadd_back(lst, ft_lstnew(0));
	printf("		size after adding 1 element at the end of an empty list = %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstdelfirst(lst);
	printf("		size after removing 1 element from the list = %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstadd_back(lst, ft_lstnew(0));
	printf("		size after adding 1 element at the end of an empty list = %d\n", ft_lstsize(lst));
	ft_lstclear(lst);
	printf("		size after clearing the list = %d\n", ft_lstsize(lst));

	//test add front: with both delfirst and lstclear
		lst = NULL;
	printf("	ft_lstnew and ft_lstadd_front\n");
	ft_lstadd_front(lst, ft_lstnew(0));
	printf("		size after adding 1 element to empty list = %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstdelfirst(lst);
	printf("		size after removing 1 element from the list = %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstadd_front(lst, ft_lstnew(0));
	printf("		size after adding 1 element to empty list = %d\n", ft_lstsize(lst));
	ft_lstclear(lst);
	printf("		size after clearing the list = %d\n", ft_lstsize(lst));


	//single element list check
	printf("Single element checks:\n");

	printf("	ft_lstnew\n");
	node = ft_lstnew(0);
	lst = &node;
	printf("		Passed\n");

	printf("	ft_putlst_fd\n");
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	printf("	ft_lstdelfirst\n");
	ft_lstdelfirst(lst);
	printf("	do i fail here1\n");
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	node = ft_lstnew(0);
	lst = &node;
	printf("	ft_lstclear\n");
	ft_lstclear(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	node = ft_lstnew(0);
	lst = &node;
	printf("	ft_lstlast\n");
	printf("		last element's nb = %d\n", ft_lstlast(lst)->nb);
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	printf("	ft_lstsize\n");
	printf("		size = %d\n", ft_lstsize(lst));
	printf("		Passed\n");

	//test extra functions for size 1
	//test add front
	printf("	ft_lstadd_back\n");
	node = ft_lstnew(0);
	lst = &node;
	printf("		size before add back = %d\n", ft_lstsize(lst));
	//test add back

	//all the tests for size n
}