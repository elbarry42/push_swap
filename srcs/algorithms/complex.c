/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:55:03 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/14 13:29:08 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	printf_stacks(t_ps ps)
{
	while (ps.stack_a->next)
	{
		ft_printf("A : %d", ps.stack_a->value);
		ps.stack_a = ps.stack_a->next;
	}
	while (ps.stack_b->next)
	{
		ft_printf("B : %d", ps.stack_b->value);
		ps.stack_b = ps.stack_b->next;
	}
}

void	intialize_index(t_ps ps)
{
	int		i;
	t_stack	*shuttle;

	i = 0;
	shuttle = ps.stack_a;
	while (shuttle->next)
	{
		shuttle->index = i++;
		shuttle = shuttle->next;
	}
	i = 0;
	shuttle = ps.stack_b;
	while (shuttle->next)
	{
		shuttle->index = i++;
		shuttle = shuttle->next;
	}
}

void	switch_nodes(t_ps ps, t_stack *stack, int i, int j)
{
	// ft_printf("stacka\nadresse : %p\nvaleur : %d\n index : %d\n", ps.stack_a, ps.stack_a->value, ps.stack_a->index);
	while (ps.stack_a->index != i)
		rotate(&stack);
	pb(&stack, &ps.stack_b);
	while (ps.stack_a->index != j)
		rotate(&stack);
	pa(&ps.stack_a, &ps.stack_b);
	rotate(&stack);
	pb(&ps.stack_a, &ps.stack_b);
}

void	push_at_index(t_ps ps, int i)
{
	while (ps.stack_a->index != i)
		rotate(&ps.stack_a);

	// a optimiser avec sois rotate sois rrotate
	pa(&ps.stack_a, &ps.stack_b);
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

void	hoare_partition(t_ps ps, t_stack *stack)
{
	int	median_of_three;
	int	i;
	int	j;

	i = 0;
	j = stack_size(stack) - 1;
	median_of_three = find_median_value(stack);
	while (i < j)
	{
		if (value_at_index(stack, i) < median_of_three)
			push_at_index(ps, i);
		else
		{
			if (value_at_index(stack, j) > median_of_three)
				j--;
			else
			{
				switch_nodes(ps, ps.stack_a, i, j);
				j--;
			}
		}
	}
}

void	complex(t_ps ps)
{
	int	lenght_a;
	int	lenght_b;

	lenght_a = stack_size(ps.stack_a);
	lenght_b = stack_size(ps.stack_b);
	if (lenght_a > 1)
	{
		hoare_partition(ps, ps.stack_a);
		intialize_index(ps);
		printf_stacks(ps);
		complex(ps);
	}
	// if (lenght_b > 1)
	// {
	// 	hoare_partition(ps, ps.stack_b);
	// 	complex(t_ps);
	// }
}
