/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:53:19 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/21 17:43:53 by elbarry          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_pars	*values;
	int		i;
	char	*line = NULL;

	if (argc < 2)
		return (0);

	values = parsing(argc, argv);
	if (!values)
		return (0);
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	ps.bench = NULL;
	i = 0;
	while (i < values->counter)
		stack_add_back(&ps.stack_a, stack_new(values->array[i++], 0));
	while ((line = read_op()))

	if (is_sorted(ps.stack_a) && stack_is_empty(ps.stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&ps, values);
	return (0);
}