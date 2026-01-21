/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:35:20 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/20 17:23:57 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	check_two_nodes(t_ps *ps)
{
	if (ps->stack_a->value > ps->stack_a->next->value)
		sa(&ps->stack_a);
}

static	void	check_three_nodes(t_ps *ps)
{
	if (ps->stack_a->value > ps->stack_a->next->value
		&& ps->stack_a->value > ps->stack_a->next->next->value)
		ra(&ps->stack_a);
	else if (ps->stack_a->next->value > ps->stack_a->value
		&& ps->stack_a->next->value > ps->stack_a->next->next->value)
		rra(&ps->stack_a);
	check_two_nodes(ps);
}

void	few_numbers(t_ps *ps)
{
	int		i;
	int		lenght;

	i = 0;
	lenght = stack_size(ps->stack_a);
	if (lenght == 2)
		check_two_nodes(ps);
	else if (lenght == 3)
		check_three_nodes(ps);
	else if (lenght > 3)
	{
		while (lenght-- > 3)
		{
			push_at_index_a(ps, find_smallest_number(ps));
			i++;
		}
		check_three_nodes(ps);
		while (i-- > 0)
			pa(ps);
	}
}
