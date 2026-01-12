/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:26:03 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/12 14:29:14 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_parsing
{
	int		bench;
	int		counter;
	char	*algo_type;
	int		*array;
}t_pars;

typedef struct s_stack
{
	int		value;
	int		index;
	struct	s_stack	*prev;
	struct	s_stack	*next;
} t_stack;

typedef struct s_push_swap
{
	t_stack *stack_a;
	t_stack	*stack_b;
} t_ps;

t_pars	*parsing(int argc, char **argv);
t_stack *stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	ra(t_stack **a);
#endif