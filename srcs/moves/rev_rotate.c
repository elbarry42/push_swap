/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:06:25 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/20 17:53:05 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_ps *ps)
{
	if (!ps || !ps->stack_a)
		return ;
	rev_rotate(&ps->stack_a);
	write(1, "rra\n", 4);
	ps->bench->rra++;
}

void	rrb(t_ps *ps)
{
	if (!ps || !ps->stack_b)
		return ;
	rev_rotate(&ps->stack_b);
	write(1, "rrb\n", 4);
	ps->bench->rrb++;
}

void	rrr(t_ps *ps)
{
	if (!ps)
		return ;
	rev_rotate(&ps->stack_a);
	rev_rotate(&ps->stack_b);
	write(1, "rrr\n", 4);
	ps->bench->rrr++;
}
