/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:55:57 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/12 18:32:16 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

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

int main(int argc, char **argv)
{
    t_ps   	ps;
	t_pars	*values;
    int    	i;

	i = 0;
    if (argc < 2)
        return (0);
    values = parsing(argc, argv);
    if (!values)
		return (1);
	ps.stack_a = NULL;
    ps.stack_b = NULL;
    i = 0;
    while (i < values->counter)
	{
        stack_add_back(&ps.stack_a, stack_new(values->array[i++]));
	}
	// i = 0;
	// while (i < values->counter)
	// {
	// 	ft_printf("%d\n", ps.stack_a->value);
	// 	ft_printf("%d\n", ps.stack_a->index);
	// 	ra(&ps.stack_a);
	// 	i++;
	// }
	// complex(ps, values);
	if (values->array)
		free(values->array);
	free(values);
	free_stack(ps.stack_a);
	free_stack(ps.stack_b);
    return (0);
}
