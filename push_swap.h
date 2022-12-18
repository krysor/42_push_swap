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

#include <stdio.h>//delete at the end

t_list	**ft_parse(int argc, char *argv[]);
void	*ft_atopi(char *str);
int		ft_isdup(t_list **lst);
char	*ft_solve(t_list **a);
t_list 	**ft_lstdup(t_list **lst);
int		ft_issorted(t_list **lst);
t_list	**ft_lstdouble(t_list **lst);

void	*ft_contdup(void *content);

t_list	**ft_lstinit(void);

void	ft_push(t_list **src, t_list **dst);
void	ft_swap(t_list **lst);
void	ft_rotate(t_list **lst);
void	ft_revrotate(t_list **lst);

char	*ft_strempty(void);

int ft_putbest(t_list **a, t_list **b, char *result);

void	ft_putlst_fd(t_list **lst, int fd);//delete at the end

void	ft_get_nb_rb(t_list **rb);
void	ft_get_nb_rrb(t_list **rrb);
void	ft_get_nb_ra(t_list **ra, t_list **a);
int		ft_ra_iszero(t_list *tempra, t_list **a);
int		ft_ra_iselse(t_list *tempra, t_list *tempa);
void	ft_get_nb_rra(t_list **rra, t_list **a);

void	ft_setbestmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
int		*ft_getbestmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
int		ft_max(int nb1, int nb2);

#endif