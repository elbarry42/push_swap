/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:15:31 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/21 12:08:34 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_index(t_ps *ps)
{
	int		i;
	t_stack	*shuttle;

	i = 0;
	shuttle = ps->stack_a;
	while (shuttle)
	{
		shuttle->index = i++;
		shuttle = shuttle->next;
	}
	i = 0;
	shuttle = ps->stack_b;
	while (shuttle)
	{
		shuttle->index = i++;
		shuttle = shuttle->next;
	}
}

void	simple(t_ps *ps)
{
	int	smallest_index;
	int	lenght;

	lenght = stack_size(ps->stack_a);
	if (lenght <= 4)
	{
		few_numbers(ps);
		return ;
	}
	while (ps->stack_a->next)
	{
		initialize_index(ps);
		smallest_index = find_smallest_number(ps);
		push_at_index_a(ps, smallest_index);
	}
	while (ps->stack_b)
		pa(ps);
}
