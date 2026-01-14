/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:10:17 by elbarry           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/14 12:28:52 by larchimb         ###   ########.fr       */
=======
/*   Updated: 2026/01/13 17:03:10 by elbarry          ###   ########.fr       */
>>>>>>> b588d3f1e8c08324c2a1547ad52a1ff00442f869
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	swapped;

	if (!tab || size < 2)
		return ;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

static int	*stack_to_array(t_stack *stack, int size)
{
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);

	i = 0;
	while (stack)
	{
		tab[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (tab);
}

static void	set_index(t_stack *stack, int *sorted_tab, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (sorted_tab[i] == stack->value)
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	assign_index(t_stack *stack_a)
{
	int	size;
	int	*tab;

	if (!stack_a)
		return ;

	size = stack_size(stack_a);
	tab = stack_to_array(stack_a, size);
	if (!tab)
		return ;

	sort_int_tab(tab, size);
	set_index(stack_a, tab, size);
	free(tab);
}
