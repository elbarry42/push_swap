/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:11:23 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/19 18:28:00 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_bis;

	i = 0;
	s_bis = (unsigned char *) s;
	while (i < n)
	{
		s_bis[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

static void	increment_stats(char *op, t_bench *b)
{
	if (!ft_strcmp(op, "sa"))
		b->sa++;
	else if (!ft_strcmp(op, "sb"))
		b->sb++;
	else if (!ft_strcmp(op, "ss"))
		b->ss++;
	else if (!ft_strcmp(op, "pa"))
		b->pa++;
	else if (!ft_strcmp(op, "pb"))
		b->pb++;
	else if (!ft_strcmp(op, "ra"))
		b->ra++;
	else if (!ft_strcmp(op, "rb"))
		b->rb++;
	else if (!ft_strcmp(op, "rr"))
		b->rr++;
	else if (!ft_strcmp(op, "rra"))
		b->rra++;
	else if (!ft_strcmp(op, "rrb"))
		b->rrb++;
	else if (!ft_strcmp(op, "rrr"))
		b->rrr++;
}

void	bench_apply(char *op, t_ps *ps, t_bench *b)
{
	if (!ft_strcmp(op, "sa"))
		sa(&ps->stack_a);
	else if (!ft_strcmp(op, "sb"))
		sb(&ps->stack_b);
	else if (!ft_strcmp(op, "ss"))
		ss(&ps->stack_a, &ps->stack_b);
	else if (!ft_strcmp(op, "pa"))
		pa(&ps->stack_a, &ps->stack_b);
	else if (!ft_strcmp(op, "pb"))
		pb(&ps->stack_a, &ps->stack_b);
	else if (!ft_strcmp(op, "ra"))
		ra(&ps->stack_a);
	else if (!ft_strcmp(op, "rb"))
		rb(&ps->stack_b);
	else if (!ft_strcmp(op, "rr"))
		rr(&ps->stack_a, &ps->stack_b);
	else if (!ft_strcmp(op, "rra"))
		rra(&ps->stack_a);
	else if (!ft_strcmp(op, "rrb"))
		rrb(&ps->stack_b);
	else if (!ft_strcmp(op, "rrr"))
		rrr(&ps->stack_a, &ps->stack_b);

	increment_stats(op, b);
	b->total++;
}

void	print_bench(t_bench *b)
{
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putdouble_fd(b->disorder * 100, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy:   ", 2);
	ft_putstr_fd(b->strategy_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(b->complexity_class, 2);
	ft_putstr_fd("\n[bench] total_ops:  ", 2);
	ft_putnbr_fd(b->total, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(b->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putchar_fd('\n', 2);
}
