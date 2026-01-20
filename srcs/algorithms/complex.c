/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:55:03 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/20 15:54:51 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	specific_case(t_ps *ps, int lenght)
{
	if (lenght <= 5)
	{
		few_numbers(ps);
		return (1);
	}
	return (0);
}

static int	find_amount_of_bit(int lenght)
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

void	complex(t_ps *ps)
{
	int	lenght;
	int	bit;
	int	nb_bit;

	lenght = stack_size(ps->stack_a);
	if (specific_case(ps, lenght) == 1)
		return ;
	nb_bit = find_amount_of_bit(lenght);
	bit = 0;
	while (bit < nb_bit)
	{
		lenght = stack_size(ps->stack_a);
		while (lenght-- > 0)
		{
			if (!(ps->stack_a->index & (1 << bit)))
				pb(ps);
			else
				ra(&ps->stack_a);
		}
		while (ps->stack_b)
			pa(ps);
		bit++;
	}
}
