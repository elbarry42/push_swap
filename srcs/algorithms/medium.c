/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:17:53 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/22 15:42:07 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_a_to_chunk(t_ps *ps, int min, int max)
{
	int	pos;
	int	size;

	pos = position_of_next_chunk(ps->stack_a, min, max);
	size = stack_size(ps->stack_a);
	if (pos <= size / 2)
		ra(ps);
	else
		rra(ps);
}

static void	next_chunk(int *min, int *max, int size)
{
	*min += size;
	*max += size;
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
			pb(ps);
			mid = (chunk_min + chunk_max) / 2;
			if (ps->stack_b->index < mid)
				rb(ps);
		}
		else
			move_stack_a_to_chunk(ps, chunk_min, chunk_max);
		if (chunk_finished(ps->stack_a, chunk_min, chunk_max))
			next_chunk(&chunk_min, &chunk_max, chunk_size);
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
			pa(ps);
		else
		{
			pos = position_of_index(ps->stack_b, max);
			size = stack_size(ps->stack_b);
			if (pos <= size / 2)
				rb(ps);
			else
				rrb(ps);
		}
	}
}

void	medium(t_ps *ps)
{
	int	lenght;

	lenght = stack_size(ps->stack_a);
	if (lenght <= 5)
	{
		few_numbers(ps);
		return ;
	}
	if (!ps || !(ps)->stack_a)
		return ;
	push_chunks(ps);
	push_back_to_a(ps);
}
