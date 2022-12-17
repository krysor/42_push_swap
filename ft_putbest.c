#include "push_swap.h"

void	ft_putbest_free(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
void	ft_get_nb_rb(t_list **rb);
void	ft_get_nb_rrb(t_list **rrb);
void	ft_get_nb_ra(t_list **ra, t_list **a);
int		ft_ra_iszero(t_list *tempra, t_list **a);
int		ft_ra_iselse(t_list *tempra, t_list *tempa);
void	ft_get_nb_rra(t_list **rra, t_list **a);

	//this is about ONE SINGLE MOVE
int ft_putbest(t_list **a, t_list **b, char *result)
{
	t_list	**ra;
	t_list	**rra;
	t_list	**rb;
	t_list	**rrb;

	ra = ft_lstdup(b);
	rra = ft_lstdup(b);
	rb = ft_lstdup(b);
	rrb = ft_lstdup(b); 
	if (ra == NULL || rra == NULL || rb == NULL || rrb == NULL)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		return (0);
	}
	ft_get_nb_ra(ra, a);
	ft_get_nb_rra(rra, a);
	ft_get_nb_rb(rb);
	ft_get_nb_rrb(rrb);
	(void)b;
	(void)result;
	ft_getbestmoves(ra, rra, rb, rrb);
	(void)ft_pickbest_move(ra, rra, rb, rrb);//call this inside move execute function
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
	//calculate which should get put first
		//calculate how many instructions of each type for each
			//get the information
				//how many moves in a//done
				//how many moves in b//done
				//magic 2x2 table
			//calculate each information//done
		//choose the best one
			//iterate over data structure and save the current best choice
		//append the instructions to the instructions strings
			//possibly modify first if possible to optimize by 2 sides singel instruction moves
	//execute the best one
	ft_putbest_free(ra, rra, rb, rrb);
	return (1);
}

//finish this one or think about how to get it
int	ft_pickbest_move(t_list **ra, t_list **rra, t_list **rb, t_list **rrb)
{
	int	moves;

	t_list *tempra;
	t_list *temprra;
	t_list *temprb;
	t_list *temprrb;

	tempra = *ra;
	temprra = *rra;
	temprb = *rb;
	temprrb = *rrb;
	moves = ft_get_nbmoves(tempra, temprra, temprb, temprrb);
	while (tempra)
	{
		if (ft_get_nbmoves(tempra, temprra, temprb, temprrb) < moves)
			moves = ft_getmoves(tempra, temprra, temprb, temprrb);
		tempra = tempra->next;
		temprra = temprra->next;
		temprb = temprb->next;
		temprrb = temprrb->next;
	}
	return (moves);
}

int	ft_get_nbmoves(t_list *ra, t_list *rra, t_list *rb, t_list *rrb)
{
	int	rarb;
	int	rarrb;
	int	rrarb;
	int	rrarrb;
	
	rarb = ft_max(*(int *)(tempra->content), *(int *)(temprb->content));
	rarrb = *(int *)(tempra->content) + *(int *)(temprrb->content);
	rrarb = *(int *)(temprra->content) + *(int *)(temprb->content);
	rrarrb = ft_max(*(int *)(temprra->content), *(int *)(temprrb->content));
	if (rarb <= rarrb && rarb <= rrarb && rarb <= rrarrb)
		return (rarb);
	else if (rarrb <= rarb && rarrb <= rrarb && rarrb <= rrarrb)
		return (rarrb);
	else if (rrarb <= rarb && rrarb <= rarrb && rrarb <= rrarrb)
		return (rrarb);
	else if (rrarrb <= rarb && rrarrb <= rarrb && rrarrb <= rrarb)
		return (rrarrb);
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