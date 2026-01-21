/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:06:37 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/21 12:23:28 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_ps *ps)
{
	if (!ps || !ps->stack_a)
		return ;
	rotate(&ps->stack_a);
	write(1, "ra\n", 3);
	ps->bench->ra++;
}

void	rb(t_ps *ps)
{
	if (!ps || !ps->stack_b)
		return ;
	rotate(&ps->stack_b);
	write(1, "rb\n", 3);
	ps->bench->rb++;
}

void	rr(t_ps *ps)
{
	if (!ps)
		return ;
	rotate(&ps->stack_a);
	rotate(&ps->stack_b);
	write(1, "rr\n", 3);
	ps->bench->rr++;
}
