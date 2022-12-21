#include "push_swap.h"

static void	ft_putbest_free(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb);

char	*ft_putbest(t_list **a, t_list **b, char *result)
//shorten by adding protections to get_get_nb_* and writing ra and ft_get on same line
{
	t_list	**ra;
	t_list	**rra;
	t_list	**rb;
	t_list	**rrb;
	int		*moves;

	ra = ft_lstdup(b);
	rra = ft_lstdup(b);
	rb = ft_lstdup(b);
	rr = ft_lstdup(b);
	if (ra == NULL || rra == NULL || rb == NULL || rrb == NULL)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		return (NULL);
	}
	ft_get_nb_ra(ra, a);
	ft_get_nb_rra(rra, a);
	ft_get_nb_rb(rb);
	ft_get_nb_rrb(rrb);
	ft_getallbestmoves(ra, rra, rb, rrb);
	moves = ft_getthebestmoves(ra, rra, rb, rrb);
	if (!moves)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		free(result);
		return (NULL);
	}
	result = ft_makethebestmoves(a, b, result, moves);
	ft_putbest_free(ra, rra, rb, rrb);
	free(moves);
	return (result);
}

static void	ft_putbest_free(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb)
{
	ft_lstclear(ra, (void *)free);
	ft_lstclear(rra, (void *)free);
	ft_lstclear(rb, (void *)free);
	ft_lstclear(rrb, (void *)free);
	free(ra);
	free(rra);
	free(rb);
	free(rrb);
}
