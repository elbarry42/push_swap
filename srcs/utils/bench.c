/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:11:23 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/20 14:47:25 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

static void	increment_stats(char *op, t_ps *ps)
{
	if (!ft_strcmp(op, "sa"))
		ps->bench->sa++;
	else if (!ft_strcmp(op, "sb"))
		ps->bench->sb++;
	else if (!ft_strcmp(op, "ss"))
		ps->bench->ss++;
	else if (!ft_strcmp(op, "pa"))
		ps->bench->pa++;
	else if (!ft_strcmp(op, "pb"))
		ps->bench->pb++;
	else if (!ft_strcmp(op, "ra"))
		ps->bench->ra++;
	else if (!ft_strcmp(op, "rb"))
		ps->bench->rb++;
	else if (!ft_strcmp(op, "rr"))
		ps->bench->rr++;
	else if (!ft_strcmp(op, "rra"))
		ps->bench->rra++;
	else if (!ft_strcmp(op, "rrb"))
		ps->bench->rrb++;
	else if (!ft_strcmp(op, "rrr"))
		ps->bench->rrr++;
}

void	bench_apply(char *op, t_ps *ps)
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

	increment_stats(op, ps);
	ps->bench->total++;
}

void	print_bench(t_ps *ps)
{
	ft_printf("[bench] disorder : %d,%d\n", (int)ps->bench->disorder * 100,
		(int)ps->bench->disorder * 10000 - ((int)ps->bench->disorder * 100) * 100);
	ft_printf("[bench] total_ops : %d\n\n", ps->bench->total);

	ft_printf("[bench] sa:%d sb:%d ss:%d pa:%d pb:%d\n",
		ps->bench->sa, ps->bench->sb, ps->bench->ss, ps->bench->pa, ps->bench->pb);

	ft_printf("[bench] ra:%d rb:%d rr:%d rra:%d rrb:%d rrr:%d\n",
		ps->bench->ra, ps->bench->rb, ps->bench->rr, ps->bench->rra, ps->bench->rrb, ps->bench->rrr);
}

