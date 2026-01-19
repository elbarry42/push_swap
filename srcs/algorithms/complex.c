/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:55:03 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/19 12:34:47 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// // void	push_at_index(t_ps *ps, int i)
// // {
// // 	while (ps->stack_a->index != i)
// // 		rotate(&ps->stack_a);

// // 	// a optimiser avec sois rotate sois rrotate
// // 	pa(&ps->stack_a, &ps->stack_b);
// // }

// int	value_at_index(t_stack *stack, int index)
// {
// 	t_stack	*shuttle;

// 	shuttle = stack;
// 	while (shuttle->index != index)
// 		shuttle = shuttle->next;
// 	return (shuttle->value);
// }

// int	find_median_value(t_stack *stack)
// {
// 	int	a;
// 	int	b;
// 	int	c;
// 	int	lenght;

// 	lenght = stack_size(stack);
// 	a = value_at_index(stack, 0);
// 	b = value_at_index(stack, lenght / 2);
// 	c = value_at_index(stack, lenght - 1);

// 	if ((a > b && a < c) || (a > c && a < b))
// 		return (a);
// 	else if ((b > a && b < c) || (b > c && b < a))
// 		return (b);
// 	else
// 		return (c);
// }

// void	partition_b(t_ps *ps, int lenght)
// {
// 	int	median_of_three;
// 	int	i;
// 	int	counter;

// 	i = 0;
// 	counter = 0;
// 	if (lenght == 0 || !ps->stack_b)
// 		return;
// 	if (lenght == 1)
// 	{
// 		pa(&ps->stack_a, &ps->stack_b);
// 		return;
// 	}
// 	if (lenght >= 3)
// 		median_of_three = find_median_value(ps->stack_b);
// 	else
// 	median_of_three = ps->stack_b->value;
// 	while (i < lenght)
// 	{
// 		if (!ps->stack_b)
// 			break;
// 		if (ps->stack_b->value > median_of_three)
// 			pa(&ps->stack_a, &ps->stack_b);
// 		else
// 		{
// 			rb(&ps->stack_b);
// 			counter++;
// 		}
// 		i++;
// 	}
// 	while (counter-- > 0)
// 		rrb(&ps->stack_b);
// }

// void	partition_a(t_ps *ps)
// {
// 	int	median_of_three;
// 	int	i;
// 	int	lenght;
// 	int	counter;

// 	i = 0;
// 	counter = 0;
// 	lenght = stack_size(ps->stack_a);
// 	if (lenght == 0)
// 		return ;
// 	if (lenght >= 3)
// 		median_of_three = find_median_value(ps->stack_a);
// 	else
// 	median_of_three = ps->stack_a->value;
// 	while (i < lenght)
// 	{
// 		if (ps->stack_a->value <= median_of_three)
// 		{
// 			pb(&ps->stack_a, &ps->stack_b);
// 			counter++;
// 		}
// 		else
// 			ra(&ps->stack_a);
// 		i++;
// 	}
// 	initialize_index(ps);
// 	partition_a(ps);
// 	initialize_index(ps);
// 	partition_b(ps, counter);
// }
int	find_amount_of_bit(int lenght)
{
	int	counter;

	counter = 0;
	while (lenght >= 1)
	{
		lenght = lenght / 2;
		counter++;
	}
	return (counter);
}

// void	put_index(t_ps *ps)
// {
// 	int		index;
// 	int		min;
// 	t_stack	*shuttle;

// 	index = 0;
// 	shuttle = ps->stack_a;
// 	min = shuttle->value;
// 	while (shuttle)
// 	{
// 		if(shuttle->value < min)
// 			index++;
// 		shuttle = shuttle->next;
// 	}
// 	ps->stack_a->index = index;
// }

void	complex(t_ps *ps)
{
	int	lenght;
	int	bit;
	int	nb_bit;

	lenght = stack_size(ps->stack_a);
	nb_bit = find_amount_of_bit(lenght);
	while (lenght-- > 0)
	{
		if (!(ps->stack_a->index & (1 << 0)))
			pb(&ps->stack_a, &ps->stack_b);
		else
			ra(&ps->stack_a);
	}
	while (ps->stack_b)
		pa(&ps->stack_a, &ps->stack_b);
	bit = 1;
	while (bit < nb_bit)
	{
		lenght = stack_size(ps->stack_a);
		while (lenght-- > 0)
		{
			if (!(ps->stack_a->index & (1 << bit)))
				pb(&ps->stack_a, &ps->stack_b);
			else
				ra(&ps->stack_a);
		}
		while (ps->stack_b)
			pa(&ps->stack_a, &ps->stack_b);
		bit++;
	}
}
