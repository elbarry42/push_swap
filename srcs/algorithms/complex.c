/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:55:03 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/15 15:01:06 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	initialize_index(t_ps *ps)
{
	int		i;
	t_stack	*shuttle;

	i = 0;
	shuttle = ps->stack_a;
	while (shuttle)
	{
		shuttle->index = i++;
		shuttle = shuttle->next;
	}
	i = 0;
	shuttle = ps->stack_b;
	while (shuttle)
	{
		shuttle->index = i++;
		shuttle = shuttle->next;
	}
}

void	push_at_index_a(t_ps *ps, int i)
{
	while (ps->stack_a->index != i)
		rotate(&ps->stack_a);

	// a optimiser avec sois rotate sois rrotate
	pa(&ps->stack_a, &ps->stack_b);
}

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
	median_of_three = find_median_value(ps->stack_a);
	while (i < lenght)
	{
		if (value_at_index(ps->stack_a, i) < median_of_three)
			push_at_index_a(ps, i++);
		else
			i++;
	}
}

void	complex(t_ps *ps, int lenght_a)
{
	int	lenght_b;

	initialize_index(ps);
	lenght_a = stack_size(ps->stack_a);
	if (lenght_a == 0)
		return ;
	lenght_b = stack_size(ps->stack_b);
	if (lenght_a <= 2)
		ft_printf("test\n");
	else if ((lenght_a > 2))
	{
		partition_a(ps);
		complex(ps, lenght_a);
	}
	// if (lenght_b > 1)
	// {
	// 	hoare_partition(ps, ps->stack_b);
	// 	complex(t_ps);
	// }
}
