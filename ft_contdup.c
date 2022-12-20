/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:08:20 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 13:09:35 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_contdup(void *content)
{
	int	*dup;

	if (content == NULL)
		return (NULL);
	dup = malloc(sizeof(content));
	if (dup == NULL)
		return (NULL);
	*dup = *(int *)content;
	return (dup);
}
