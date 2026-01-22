/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:26:03 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/22 14:47:32 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	float	disorder;
	char	*strategy;
	char	*complexity;
}	t_bench;

typedef struct s_parsing
{
	int		bench;
	int		counter;
	char	*algo_type;
	int		*array;
}	t_pars;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_bench	*bench;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_ps;

t_pars	*parsing(int argc, char **argv);
t_stack	*stack_new(int value, int index);

void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);

/* algorithms */
void	simple(t_ps *ps);
void	medium(t_ps *ps);
void	complex(t_ps *ps);
char	*adaptive(t_ps *ps, float disorder);

/* swap */
void	swap(t_stack **stack);
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);

/* push */
void	pa(t_ps *ps);
void	pb(t_ps *ps);

/* rotate */
void	rotate(t_stack **stack);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);

/* reverse rotate */
void	rev_rotate(t_stack **stack);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

/* helpers*/
void	assign_index(t_stack *stack_a);
void	stack_add_back(t_stack **stack, t_stack *new);
void	few_numbers(t_ps *ps);
void	push_at_index_a(t_ps *ps, int index);
void	print_bench(t_ps *ps);
int		stack_size(t_stack *stack);
int		get_chunk_count(int size);
int		chunk_finished(t_stack *a, int chunk_min, int chunk_max);
int		find_max_index(t_stack *stack);
int		position_of_index(t_stack *stack, int target_index);
int		find_smallest_number(t_ps *ps);
int		position_of_next_chunk(t_stack *a, int min, int max);
float	compute_disorder(t_stack *a);

#endif