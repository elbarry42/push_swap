/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:36:21 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/14 13:35:51 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack *stack_new(int value, int index)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);

    node->value = value;
	node->index = index;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;
	static int	index = 0;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->index = index++;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	new->index = index++;

}

