/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:55:57 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/15 18:53:22 by larchimb         ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_pars	*values;
	int		i;

	if (argc < 2)
		return (0);

	values = parsing(argc, argv);
	if (!values)
		return (1);
	ps.stack_a = NULL;
	ps.stack_b = NULL;

	i = 0;
	while (i < values->counter)
		stack_add_back(&ps.stack_a, stack_new(values->array[i++], 0));

	// t_stack	*tmp;
	// assign_index(ps.stack_a);
	// ft_printf("=== STACK A (value | index) ===\n");
	// tmp = ps.stack_a;
	// while (tmp)
	// {
	// 	ft_printf("value: %d | index: %d\n", tmp->value, tmp->index);
	// 	tmp = tmp->next;
	// }

	// ft_printf("\n=== AFTER ra ===\n");
	// ra(&ps.stack_a);
	// tmp = ps.stack_a;
	// while (tmp)
	// {
	// 	ft_printf("value: %d | index: %d\n", tmp->value, tmp->index);
	// 	tmp = tmp->next;
	// }
	//complex(&ps, values->counter);
	printf_stacks(&ps);
	free(values->array);
	free(values);
	free_stack(ps.stack_a);
	free_stack(ps.stack_b);

	return (0);
}
