/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:15:31 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/15 18:53:14 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_index(t_ps *ps, int index)
{
	while (ps->stack_a->index != index)
		ra(&ps->stack_a);
	pb(&ps->stack_a, &ps->stack_b);
}

void	rrotate_to_index(t_ps *ps, int index)
{
	while (ps->stack_a->index != index)
		rra(&ps->stack_a);
	pb(&ps->stack_a, &ps->stack_b);
}

int	find_smallest_number(t_ps *ps)
{
	int	index;
	int	small_value;
	t_stack	*shuttle;

	shuttle = ps->stack_a;
	if (!shuttle)
		return (0);
	index = shuttle->index;
	small_value = shuttle->value;
	while (shuttle)
	{
		if (shuttle->value < small_value)
		{
			small_value = shuttle->value;
			index = shuttle->index;
		}
		shuttle = shuttle->next;
	}
	return (index);
}

void	push_at_index_a(t_ps *ps, int index)
{
	int	difference;
	int	half_size;

	difference = ps->stack_a->index - index;
	half_size = stack_size(ps->stack_a) / 2;
	if (difference > 0 && difference <= half_size)
		rrotate_to_index(ps, index);
	else if (difference > 0 && difference > half_size)
		rotate_to_index(ps, index);
	else if (difference < 0 && -difference > half_size)
		rrotate_to_index(ps, index);
	else if (difference < 0 && -difference <= half_size)
		rotate_to_index(ps, index);
	else if (difference == 0)
		pb(&ps->stack_a, &ps->stack_b);

}

void	simple(t_ps *ps)
{
	int	smallest_index;

	while(ps->stack_a->next)
	{
		smallest_index = find_smallest_number(ps);
		push_at_index_a(ps, smallest_index);
	}
	while (ps->stack_b)
		pa(&ps->stack_a, &ps->stack_b);
}