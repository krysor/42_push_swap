#include "push_swap.h"

static int	ft_isspace(char chr);
static int	ft_nbdigit(char *s);
static long int	ft_atolong(const char *nptr);

void	*ft_atopi(char *str)
{
	long int	nb;
	int			*content;
	
	nb = ft_atolong(str);
	if (nb == LONG_MIN)
		return (NULL);
	content = malloc(sizeof(int));
	if (content == NULL)
		return (NULL);
	*content = (int)nb;
	return ((void *)content);
}

static long int	ft_atolong(const char *nptr)
{
	long int	nb;
	int			sign;
	char		*str;

	nb = 0;
	sign = 1;
	str = (char *)nptr;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!ft_isdigit(*str) || (ft_nbdigit(str) > 10))
		return (LONG_MIN);
	while (ft_isdigit(*str))
		nb = nb * 10 + *str++ - '0';
	nb *= sign;
	if (nb < (long)INT_MIN || nb > (long)INT_MAX)
		return (LONG_MIN);
	return (nb);
}

static int	ft_isspace(char chr)
{
	if (chr == ' ' || chr == '\f' || chr == '\n'
		|| chr == '\r' || chr == '\t' || chr == '\v')
		return (1);
	return (0);
}

static int	ft_nbdigit(char *s)
{
	int	nb;

	nb = 0;
	while (*s && ft_isdigit(*s))
	{
		nb++;
		s++;
	}	
	return (nb);
}