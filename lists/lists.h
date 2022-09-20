#ifndef LISTS_H
# define LISTS_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*prev;
	struct s_list	*next;
}					l_list;
l_list	*ft_lstnew(int nb);
void	ft_lstadd_front(l_list **lst, l_list *new);
int		ft_lstsize(l_list **lst);
l_list	*ft_lstlast(l_list **lst);
void	ft_lstadd_back(l_list **lst, l_list *new);

//l_list	**ft_lstdelfirst(l_list **lst);
void	ft_lstdelfirst(l_list **lst);

void	ft_lstclear(l_list **lst);
void	ft_putlst_fd(l_list **lst, int fd);

#endif