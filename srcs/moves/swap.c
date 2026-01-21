/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:38:45 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/21 12:23:24 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_ps *ps)
{
	if (!ps || !ps->stack_a)
		return ;
	swap(&ps->stack_a);
	write(1, "sa\n", 3);
	ps->bench->sa++;
}

void	sb(t_ps *ps)
{
	if (!ps || !ps->stack_b)
		return ;
	swap(&ps->stack_b);
	write(1, "sb\n", 3);
	ps->bench->sb++;
}

void	ss(t_ps *ps)
{
	if (!ps)
		return ;
	swap(&ps->stack_a);
	swap(&ps->stack_b);
	write(1, "ss\n", 3);
	ps->bench->ss++;
}
