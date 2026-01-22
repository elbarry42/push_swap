/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:53:33 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/21 17:44:46 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stack_is_empty(t_stack *b)
{
	return (b == NULL);
}

void	apply_op(char *op, t_ps *ps, t_pars *values)
{
	if (!ft_strncmp(op, "sa", 2))
		sa(ps);
	else if (!ft_strncmp(op, "sb", 2))
		sb(ps);
	else if (!ft_strncmp(op, "ss", 2))
		ss(ps);
	else if (!ft_strncmp(op, "pa", 2))
		pa(ps);
	else if (!ft_strncmp(op, "pb", 2))
		pb(ps);
	else if (!ft_strncmp(op, "ra", 2))
		ra(ps);
	else if (!ft_strncmp(op, "rb", 2))
		rb(ps);
	else if (!ft_strncmp(op, "rr", 2))
		rr(ps);
	else if (!ft_strncmp(op, "rra", 3))
		rra(ps);
	else if (!ft_strncmp(op, "rrb", 3))
		rrb(ps);
	else if (!ft_strncmp(op, "rrr", 3))
		rrr(ps);
	else
		error_exit(ps, values);
}