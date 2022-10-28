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

long int	ft_atol(const char *nptr);


t_list	**ft_parse(int argc, char *argv[]);
t_list	**ft_atolst(char **arr);
void ft_freearr(char **arr);
void ft_putarr_fd(char **arr, int fd);
/*
l_list **ft_lst_init(char **arr);
l_list **ft_lst_make(char **arr, l_list **lst);
l_list **ft_dup_check(l_list **lst);
void ft_putpnt_fd(void *pnt);
*/

#endif