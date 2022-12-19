#include "push_swap.h"

void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
void	ft_get_nb_rb(t_list **rb);
void	ft_get_nb_rrb(t_list **rrb);
void	ft_get_nb_ra(t_list **ra, t_list **a);
int		ft_ra_iszero(t_list *tempra, t_list **a);
int		ft_ra_iselse(t_list *tempra, t_list *tempa);
void	ft_get_nb_rra(t_list **rra, t_list **a);

	//this is about ONE SINGLE MOVE
char	*ft_putbest(t_list **a, t_list **b, char *result)
{
	t_list	**ra;
	t_list	**rra;
	t_list	**rb;
	t_list	**rrb;
	int		*moves;

	ra = ft_lstdup(b);
	rra = ft_lstdup(b);
	rb = ft_lstdup(b);
	rrb = ft_lstdup(b); 
	if (ra == NULL || rra == NULL || rb == NULL || rrb == NULL)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		return (NULL);
	}
	ft_get_nb_ra(ra, a);
	ft_get_nb_rra(rra, a);
	ft_get_nb_rb(rb);
	ft_get_nb_rrb(rrb);
	(void)b;
	(void)result;
	ft_setbestmoves(ra, rra, rb, rrb);
	moves = ft_getbestmoves(ra, rra, rb, rrb);
	if (!moves)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		return (NULL);
	}
	//moves = ft_executemoves(result,);
	//split move execute function in rx and rrx (since ra and or rb)

	
	printf("a: \n");
	ft_putlst_fd(a, 1);
	printf("b: \n");
	ft_putlst_fd(b, 1);
	printf("ra after\n");
	ft_putlst_fd(ra, 1);
	printf("rra after\n");
	ft_putlst_fd(rra, 1);
	printf("rb after\n");
	ft_putlst_fd(rb, 1);
	printf("rrb after\n");
	ft_putlst_fd(rrb, 1);
	
	printf("show moves: \n");
	int	i = 0;
	while (i < 4)
	{
		printf("arr[%d]: %d\n", i, moves[i]);
		i++;
	}

	//calculate which should get put first//done
		//calculate how many instructions of each type for each//done
			//get the information//done
				//how many moves in a//done
				//how many moves in b//done
				//magic 2x2 table//done
			//calculate each information//done
		//choose the best one//done
			//iterate over data structure and save the current best choice//done
		//append the instructions to the instructions strings
			//possibly modify first if possible to optimize by 2 sides singel instruction moves
	//execute the best one

	result = ft_executemoves(a, b, result, moves);

	ft_putbest_free(ra, rra, rb, rrb);
	free(moves);
	return (result);
}

char	*ft_executemoves(t_list **a, t_list **b, char *result, int *moves)
{
	if (moves[0] != -1 && moves[2] != -1)
		result = ft_executerr(a, b, result, moves);
	else if (moves[1] != -1 && moves[3] != -1)
		result = ft_executerrr(a, b, result, moves);
	else
	{
		while (result != NULL && moves[3]--)
			result = ft_rotatesave(b, result, "rrb\n\0");
		while (result != NULL && moves[2]--)
			result = ft_rotatesave(b, result, "rb\n\0");
		if (result != NULL)
			result = ft_pushsave(b, a, result, "pa\n\0");
		while (result != NULL && moves[3]--)
			result = ft_rotatesave(b, result, "rrb\n\0");
		while (result != NULL && moves[2]--)
			result = ft_rotatesave(b, result, "rb\n\0");
	}
	//free(moves);
	return (result);
}

char	*ft_executerr(t_list **a, t_list **b, char *result, int *moves)
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
		result = ft_pushsave(b, a, result, "pa\n\0");
	else
		return (NULL);
	return (result);
}

char	*ft_executerrr(t_list **a, t_list **b, char *result, int *moves)
{
	while (result != NULL && moves[1] && moves[3])
	{
		result = ft_revrotatesave(a, result, "rrr\n\0");
		result = ft_revrotatesave(b, result, "\0");
		moves[1]--;
		moves[3]--;
	}
	while (result != NULL && moves[3]--)
		result = ft_rotatesave(b, result, "rrb\n\0");
	while (result != NULL && moves[1]--)
		result = ft_rotatesave(a, result, "rra\n\0");
	if (result != NULL)
		result = ft_pushsave(b, a, result, "pa\n\0");
	else
		return (NULL);
	return (result);
}

void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb)
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

int	ft_max(int nb1, int nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

int	ft_min(int nb1, int nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}