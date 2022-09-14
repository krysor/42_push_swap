#include "lists.h"
#include <stdio.h>

int	main(void)
{
	l_list	**lst;
	l_list	*node;
	//int		i;


	/*
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

	lst = NULL;
	printf("	ft_lstnew and ft_lstadd_back\n");
	ft_lstadd_back(lst, ft_lstnew(0));
	printf("		size after ft_lstadd_back: %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstdelfirst(lst);
	printf("		size after ft_lstdelfirst: %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstadd_back(lst, ft_lstnew(0));
	printf("		size after ft_lstadd_back: %d\n", ft_lstsize(lst));
	ft_lstclear(lst);
	printf("		size after ft_lstclear: %d\n", ft_lstsize(lst));
	printf("		Passed if size 0 everywhere\n");

	lst = NULL;
	printf("	ft_lstnew and ft_lstadd_front\n");
	ft_lstadd_front(lst, ft_lstnew(0));
	printf("		size after ft_lstadd_front: %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstdelfirst(lst);
	printf("		size after ft_lstdelfirst: %d\n", ft_lstsize(lst));
	ft_putlst_fd(lst, 1);
	ft_lstadd_front(lst, ft_lstnew(0));
	printf("		size after ft_lstadd_front: %d\n", ft_lstsize(lst));
	ft_lstclear(lst);
	printf("		size after ft_lstclear: %d\n", ft_lstsize(lst));
	printf("		Passed if size 0 everywhere\n");


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
	ft_putlst_fd(lst, 1);
	ft_lstdelfirst(lst);//second time to check if crashes
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	node = ft_lstnew(0);
	lst = &node;
	printf("	ft_lstclear\n");
	ft_lstclear(lst);
	ft_putlst_fd(lst, 1);
	ft_lstclear(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");
*/

	node = ft_lstnew(0);
	lst = &node;
	printf("	ft_lstlast\n");
	printf("		last element's nb = %d\n", ft_lstlast(lst)->nb);
	ft_putlst_fd(lst, 1);
	printf("		Passed\n");

	printf("	ft_lstsize\n");
	printf("		size = %d\n", ft_lstsize(lst));
	printf("		Passed if size = 1\n");

	//all the tests for size 2
		printf("Double element checks:\n");
	
	printf("	ft_lstadd_back\n");
	ft_lstadd_back(lst, ft_lstnew(1));
	ft_putlst_fd(lst, 1);
	printf("		Passed if 0 and 1 printed\n");

	printf("	ft_lstdelfirst\n");
	//ft_lstdelfirst(lst);
	lst = ft_lstdelfirst(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed if only 1 printed before this\n");
	printf("		size after first ft_lstdelfirst: %d\n", ft_lstsize(lst));
	//ft_lstdelfirst(lst);
	lst = ft_lstdelfirst(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed if nothing printed before this\n");
	printf("		size after second ft_lstdelfirst: %d\n", ft_lstsize(lst));

	/*
	printf("	ft_lstclear\n");
	node = ft_lstnew(0);
	lst = &node;
	ft_lstadd_back(lst, ft_lstnew(1));
	ft_putlst_fd(lst, 1);
	ft_lstclear(lst);
	ft_putlst_fd(lst, 1);
	printf("		Passed if 0 1 only printed once\n");
	//all the tests for size n
	*/
}