/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:21:45 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/14 13:28:42 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

				#include "../../include/libft.h"

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
