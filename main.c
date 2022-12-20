/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:19:29 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 16:21:00 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	**input;
	char	*result;

	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	input = ft_parse(argc, argv);
	result = ft_solve(input);
	ft_putstr_fd(result, 1);
	ft_lstclear(input, (void *)free);
	free(input);
	free(result);
	return (1);
}
