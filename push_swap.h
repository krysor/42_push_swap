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

void	ft_push(t_list **src, t_list **dst);

#endif