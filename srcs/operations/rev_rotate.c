/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:06:25 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/08 15:13:37 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack **a)
{
    t_stack *last;

    last = *a;
    while (last->next)
        last = last->next;
    last->prev->next = NULL;
    last->next = *a;
    (*a)->prev = last;
    *a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
    t_stack *last;

    last = *b;
    while (last->next)
        last = last->next;
    last->prev->next = NULL;
    last->next = *b;
    (*b)->prev = last;
    last = *b;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}