/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:42:19 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/05/18 15:50:17 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" 
# include <limits.h>

#include <stdio.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*prev;
	struct s_list	*next;
}					l_list;
long int	ft_atol(const char *nptr);

l_list	*ft_lstnew(int nb);
void	ft_lstclear(l_list **lst);
void	ft_lstadd_back(l_list **lst, l_list *new);
l_list	*ft_lstlast(l_list **lst);
void	ft_lstadd_front(l_list **lst, l_list *new);
int		ft_lstsize(l_list **lst);

#endif