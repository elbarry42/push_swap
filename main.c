/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:55:57 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/20 13:54:03 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void        printf_stacks(t_ps *ps)
{
	t_stack	*shuttle;

	shuttle = ps->stack_a;
	while (shuttle)
	{
		ft_printf("A : %d\n", shuttle->value);
		shuttle = shuttle->next;
	}
	shuttle = ps->stack_b;
	while (shuttle)
	{
		ft_printf("B : %d\n", shuttle->value);
		shuttle = shuttle->next;
	}
}

void	free_all(t_ps *ps, t_pars *values)
{
	t_stack	*tmp;

	free(values->array);
	free(values);
	while (ps->stack_a)
	{
		tmp = ps->stack_a->next;
		free(ps->stack_a);
		ps->stack_a = tmp;
	}
}

static	void	using_algo_choose(t_ps *ps, t_pars *values, float disorder)
{
	if (ft_strncmp(values->algo_type, "adaptive", 11) == 0)
		adaptive(ps, disorder);
	else if (ft_strncmp(values->algo_type, "simple", 9) == 0)
		simple(ps);
	else if (ft_strncmp(values->algo_type, "medium", 9) == 0)
		medium(ps);
	else if (ft_strncmp(values->algo_type, "complex", 10) == 0)
		complex(ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_pars	*values;
	int		i;
	float	disorder;

	if (argc < 2)
		return (0);
	values = parsing(argc, argv);
	if (!values)
		return (0);
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	i = 0;
	while (i < values->counter)
		stack_add_back(&ps.stack_a, stack_new(values->array[i++], 0));
	disorder = compute_disorder(ps.stack_a);
		if ( disorder == 0)
	{
		free_all(&ps, values);
		return (0);
	}
	assign_index(ps.stack_a);
	using_algo_choose(&ps, values, disorder);
	free_all(&ps, values);
	return (1);
}
