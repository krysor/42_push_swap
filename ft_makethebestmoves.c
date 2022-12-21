/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 10:57:52 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_makerr(t_list **a, t_list **b, char *result, int *moves);
static char	*ft_makerrr(t_list **a, t_list **b, char *result, int *moves);

char	*ft_makethebestmoves(t_list **a, t_list **b, char *result, int *moves)
{
	if (moves[0] != -1 && moves[2] != -1)
		result = ft_makerr(a, b, result, moves);
	else if (moves[1] != -1 && moves[3] != -1)
		result = ft_makerrr(a, b, result, moves);
	else
	{
		while (result != NULL && moves[0]-- > 0)
			result = ft_rotatesave(a, result, "ra\n\0");
		while (result != NULL && moves[1]-- > 0)
			result = ft_revrotatesave(a, result, "rra\n\0");
		while (result != NULL && moves[2]-- > 0)
			result = ft_rotatesave(b, result, "rb\n\0");
		while (result != NULL && moves[3]-- > 0)
			result = ft_revrotatesave(b, result, "rrb\n\0");
		if (result != NULL)
			result = ft_savepush(b, a, result, "pa\n\0");
	}
	return (result);
}

static char	*ft_makerr(t_list **a, t_list **b, char *result, int *moves)
{
	while (result != NULL && moves[0] && moves[2])
	{
		result = ft_rotatesave(a, result, "rr\n\0");
		result = ft_rotatesave(b, result, "\0");
		moves[0]--;
		moves[2]--;
	}
	while (result != NULL && moves[2]--)
		result = ft_rotatesave(b, result, "rb\n\0");
	while (result != NULL && moves[0]--)
		result = ft_rotatesave(a, result, "ra\n\0");
	if (result != NULL)
		result = ft_savepush(b, a, result, "pa\n\0");
	else
		return (NULL);
	return (result);
}

static char	*ft_makerrr(t_list **a, t_list **b, char *result, int *moves)
{
	while (result != NULL && moves[1] && moves[3])
	{
		result = ft_revrotatesave(a, result, "rrr\n\0");
		result = ft_revrotatesave(b, result, "\0");
		moves[1]--;
		moves[3]--;
	}
	while (result != NULL && moves[3]--)
		result = ft_revrotatesave(b, result, "rrb\n\0");
	while (result != NULL && moves[1]--)
		result = ft_revrotatesave(a, result, "rra\n\0");
	if (result != NULL)
		result = ft_savepush(b, a, result, "pa\n\0");
	else
		return (NULL);
	return (result);
}
