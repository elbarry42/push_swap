/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:21:45 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/20 16:43:06 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_stack	*tmp;

	if (!ps || !ps->stack_b)
		return ;
	tmp = ps->stack_b;
	ps->stack_b = tmp->next;
	if (ps->stack_b)
		ps->stack_b->prev = NULL;
	tmp->prev = NULL;
	tmp->next = ps->stack_a;
	if (ps->stack_a)
		ps->stack_a->prev = tmp;
	ps->stack_a = tmp;
	write(1, "pa\n", 3);
	ps->bench->pa++;
}

void	pb(t_ps *ps)
{
	t_stack	*tmp;

	if (!ps || !ps->stack_a)
		return ;
	tmp = ps->stack_a;
	ps->stack_a = tmp->next;
	if (ps->stack_a)
		ps->stack_a->prev = NULL;
	tmp->prev = NULL;
	tmp->next = ps->stack_b;
	if (ps->stack_b)
		ps->stack_b->prev = tmp;
	ps->stack_b = tmp;
	write(1, "pb\n", 3);
	ps->bench->pb++;
}
