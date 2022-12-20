/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:42:19 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 17:52:36 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" 
# include <limits.h>

# include <stdio.h>//delete at the end

t_list	**ft_parse(int argc, char *argv[]);
void	*ft_atopi(char *str);

char	*ft_solve(t_list **a);

t_list	**ft_lstdup(t_list **lst);

int		ft_issorted(t_list **lst);
int		ft_iscis(t_list **lst);
char	*ft_cistosorted(t_list **lst, char *result);

char	*ft_saveswap(t_list **lst, char *result, char *str);
char	*ft_savepush(t_list **src, t_list **dst, char *result, char *str);

void	ft_get_nb_rb(t_list **rb);
void	ft_get_nb_rrb(t_list **rrb);
void	ft_get_nb_ra(t_list **ra, t_list **a);
void	ft_get_nb_rra(t_list **rra, t_list **a);

void	ft_rotate(t_list **lst);
char	*ft_rotatesave(t_list **lst, char *result, char *str);
void	ft_revrotate(t_list **lst);
char	*ft_revrotatesave(t_list **lst, char *result, char *str);

char	*ft_putbest(t_list **a, t_list **b, char *result);

void	ft_putlst_fd(t_list **lst, int fd);//delete at the end



void	ft_setbestmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
int		*ft_getbestmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
int		ft_max(int nb1, int nb2);


char	*ft_executemoves(t_list **a, t_list **b, char *result, int *moves);
char	*ft_executerr(t_list **a, t_list **b, char *result, int *moves);
char	*ft_executerrr(t_list **a, t_list **b, char *result, int *moves);

#endif