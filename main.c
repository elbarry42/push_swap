/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:55:57 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/21 13:51:05 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	free_all(t_ps *ps, t_pars *values)
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
	free(ps->bench);
}

static	int	total_ops(t_bench *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
		+ bench->rrr;
	return (total);
}

static void	initialize_ps(t_ps *ps)
{
	ps->bench = malloc(sizeof(t_bench));
	if (!ps->bench)
	{
		free_all(ps, NULL);
		return ;
	}
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->bench->sa = 0;
	ps->bench->sb = 0;
	ps->bench->ss = 0;
	ps->bench->pa = 0;
	ps->bench->pb = 0;
	ps->bench->ra = 0;
	ps->bench->rb = 0;
	ps->bench->rr = 0;
	ps->bench->rra = 0;
	ps->bench->rrb = 0;
	ps->bench->rrr = 0;
	ps->bench->total = 0;
	ps->bench->disorder = 0;
	ps->bench->strategy = NULL;
	ps->bench->complexity = NULL;
}

static	char	*using_algo_choose(t_ps *ps, t_pars *values, float disorder)
{
	if (ft_strncmp(values->algo_type, "Adaptive", 9) == 0)
		return (adaptive(ps, disorder));
	else if (ft_strncmp(values->algo_type, "Simple", 7) == 0)
	{
		if (disorder == 0)
			return ("O(n²)");
		simple(ps);
		return ("O(n²)");
	}
	else if (ft_strncmp(values->algo_type, "Medium", 7) == 0)
	{
		if (disorder == 0)
			return ("O(n√n)");
		medium(ps);
		return ("O(n√n)");
	}
	else if (ft_strncmp(values->algo_type, "Complex", 8) == 0)
	{
		if (disorder == 0)
			return ("O(nlog(n))");
		complex(ps);
		return ("O(nlog(n))");
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_pars	*values;
	int		i;

	if (argc < 2)
		return (1);
	values = parsing(argc, argv);
	if (!values)
		return (1);
	i = 0;
	initialize_ps(&ps);
	if (!ps.bench)
		return (1);
	while (i < values->counter)
		stack_add_back(&ps.stack_a, stack_new(values->array[i++], 0));
	assign_index(ps.stack_a);
	ps.bench->disorder = compute_disorder(ps.stack_a);
	ps.bench->complexity = using_algo_choose(&ps, values, ps.bench->disorder);
	ps.bench->strategy = values->algo_type;
	ps.bench->total = total_ops(ps.bench);
	if (values->bench)
		print_bench(&ps);
	free_all(&ps, values);
	return (0);
}
