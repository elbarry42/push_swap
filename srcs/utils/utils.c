/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:50:04 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/21 12:08:49 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	rotate_to_index(t_ps *ps, int index, int rotation)
{
	if (rotation == 0)
	{
		while (ps->stack_a->index != index)
			ra(ps);
	}
	else
	{
		while (ps->stack_a->index != index)
			rra(ps);
	}
	pb(ps);
}

int	find_smallest_number(t_ps *ps)
{
	int		index;
	int		small_value;
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
		rotate_to_index(ps, index, 1);
	else if (difference > 0 && difference > half_size)
		rotate_to_index(ps, index, 0);
	else if (difference < 0 && - difference > half_size)
		rotate_to_index(ps, index, 1);
	else if (difference < 0 && - difference <= half_size)
		rotate_to_index(ps, index, 0);
	else if (difference == 0)
		pb(ps);
}
