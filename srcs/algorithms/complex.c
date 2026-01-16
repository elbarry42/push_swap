/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:55:03 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/16 16:33:59 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// void	push_at_index(t_ps *ps, int i)
// {
// 	while (ps->stack_a->index != i)
// 		rotate(&ps->stack_a);

// 	// a optimiser avec sois rotate sois rrotate
// 	pa(&ps->stack_a, &ps->stack_b);
// }

int	value_at_index(t_stack *stack, int index)
{
	t_stack	*shuttle;

	shuttle = stack;
	while (shuttle->index != index)
		shuttle = shuttle->next;
	return (shuttle->value);
}

int	find_median_value(t_stack *stack)
{
	int	a;
	int	b;
	int	c;
	int	lenght;

	lenght = stack_size(stack);
	a = value_at_index(stack, 0);
	b = value_at_index(stack, lenght / 2);
	c = value_at_index(stack, lenght - 1);

	if ((a > b && a < c) || (a > c && a < b))
		return (a);
	else if ((b > a && b < c) || (b > c && b < a))
		return (b);
	else
		return (c);
}

void	partition_a(t_ps *ps)
{
	int	median_of_three;
	int	i;
	int	lenght;

	i = 0;
	lenght = stack_size(ps->stack_a);
	if (lenght >= 3)
		median_of_three = find_median_value(ps->stack_a);
	else
		median_of_three = ps->stack_a->value;
	while (i < lenght)
	{
		if (ps->stack_a->value <= median_of_three)
			pb(&ps->stack_a, &ps->stack_b);
		else
			ra(&ps->stack_a);
		i++;
	}
}

void	complex(t_ps *ps, int lenght_a)
{
	int	lenght_b;

	if (lenght_a == 0)
		return ;
	lenght_b = stack_size(ps->stack_b);
	partition_a(ps);
	lenght_a = stack_size(ps->stack_a);
	initialize_index(ps);
	complex(ps, lenght_a);

	// if (lenght_b > 1)
	// {
	// 	hoare_partition(ps, ps->stack_b);
	// 	complex(t_ps);
	// }
}
