/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:21:45 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/08 14:16:20 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (!b || !*b)
		return ;

	tmp = *b;
	*b = tmp->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = *a;
	if(*a)
		(*a)->prev = tmp;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	
	tmp = *a;
	*a = tmp->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->prev =NULL;
	tmp->next = *b;
	if(*b)
		(*b)->prev = tmp;
	*b = tmp;
	write(1, "pb\n", 3);
}
