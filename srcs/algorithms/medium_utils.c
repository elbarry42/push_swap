/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:09:49 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/21 12:23:12 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int size)
{
	int	chunks;

	chunks = 1;
	while (chunks * chunks < size)
		chunks++;
	return (chunks / 2 + 1);
}

int	chunk_finished(t_stack *a, int chunk_min, int chunk_max)
{
	while (a)
	{
		if (a->index >= chunk_min && a->index <= chunk_max)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	position_of_index(t_stack *stack, int target_index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

int	position_of_next_chunk(t_stack *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}
