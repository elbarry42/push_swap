/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:26:03 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/08 11:57:22 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

// typedef struct s_node
// {
// 	int				value;
// 	//int				index;
// 	struct s_node	*prev;
// 	struct s_node	*next;
// } t_node;

typedef struct s_stack
{
	int		value;
	struct	s_stack	*prev;
	struct	s_stack	*next;
} t_stack;

typedef struct s_push_swap
{
	t_stack *stack_a;
	t_stack	*stack_b;
} t_ps;

#endif