/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:17:53 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/16 13:59:06 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_stack_a_to_chunk(t_stack **a, int min, int max)
{
	int	pos;
	int	size;

	pos = position_of_next_chunk(*a, min, max);
	size = stack_size(*a);
	if (pos <= size / 2)
		ra(a);
	else
		rra(a);
}

static void	push_chunks(t_ps *ps)
{
	int	size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	mid;

	size = stack_size(ps->stack_a);
	chunk_size = size / get_chunk_count(size);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (ps->stack_a)
	{
		if (ps->stack_a->index >= chunk_min
			&& ps->stack_a->index <= chunk_max)
		{
			pb(&ps->stack_a, &ps->stack_b);
			mid = (chunk_min + chunk_max) / 2;
			if (ps->stack_b->index < mid)
				rb(&ps->stack_b);
		}
		else
			move_stack_a_to_chunk(&ps->stack_a, chunk_min, chunk_max);
		if (chunk_finished(ps->stack_a, chunk_min, chunk_max))
		{
			chunk_min += chunk_size;
			chunk_max += chunk_size;
		}
	}
}

static void	push_back_to_a(t_ps *ps)
{
	int	max;
	int	pos;
	int	size;

	while (ps->stack_b)
	{
		max = find_max_index(ps->stack_b);
		if (ps->stack_b->index == max)
			pa(&ps->stack_a, &ps->stack_b);
		else
		{
			pos = position_of_index(ps->stack_b, max);
			size = stack_size(ps->stack_b);
			if (pos <= size / 2)
				rb(&ps->stack_b);
			else
				rrb(&ps->stack_b);
		}
	}
}

void	medium(t_ps *ps)
{
	if (!ps || !(ps)->stack_a)
		return ;
	push_chunks(ps);
	push_back_to_a(ps);
}