#include "push_swap.h"

static int	*ft_savebestmoves(t_list *ra, t_list *rra, t_list *rb, t_list *rrb);
static int	ft_getnbleastmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb);
static int	ft_getnbmoves(t_list *ra, t_list *rra, t_list *rb, t_list *rrb);

int	*ft_getbestmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb)
{
	t_list	*tempra;
	t_list	*temprra;
	t_list	*temprb;
	t_list	*temprrb;

	tempra = *ra;
	temprra = *rra;
	temprb = *rb;
	temprrb = *rrb;
	while (tempra)
	{
		if (ft_getnbleastmoves(ra, rra, rb, rrb) == ft_getnbmoves(tempra, temprra, temprb, temprrb))
			return (ft_savebestmoves(tempra, temprra, temprb, temprrb));
		tempra = tempra->next;
		temprra = temprra->next;
		temprb = temprb->next;
		temprrb = temprrb->next;
	}
	return (NULL);
}

static int	*ft_savebestmoves(t_list *ra, t_list *rra, t_list *rb, t_list *rrb)
{
	int	*bestmoves;

	bestmoves = malloc(sizeof(int) * 4);
	if (!bestmoves)
		return (NULL);
	bestmoves[0] = *(int *)(ra->content);
	bestmoves[1] = *(int *)(rra->content);
	bestmoves[2] = *(int *)(rb->content);
	bestmoves[3] = *(int *)(rrb->content);
	return (bestmoves);
}

static int	ft_getnbleastmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb)
{
	int	least_moves;
	t_list	*tempra;
	t_list	*temprra;
	t_list	*temprb;
	t_list	*temprrb;

	tempra = *ra;
	temprra = *rra;
	temprb = *rb;
	temprrb = *rrb;
	least_moves = ft_getnbmoves(tempra, temprra, temprb, temprrb);
	while (tempra)
	{
		if (ft_getnbmoves(tempra, temprra, temprb, temprrb) < least_moves)
			least_moves = ft_getnbmoves(tempra, temprra, temprb, temprrb);
		tempra = tempra->next;
		temprra = temprra->next;
		temprb = temprb->next;
		temprrb = temprrb->next;
	}
	return (least_moves);
}

static int	ft_getnbmoves(t_list *tempra, t_list *temprra, t_list *temprb, t_list *temprrb)
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
	else//if (rrarrb <= rarb && rrarrb <= rarrb && rrarrb <= rrarb)
		return (rrarrb);
}