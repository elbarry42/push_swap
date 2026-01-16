/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:26:03 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/16 18:06:16 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_bench
{
    int sa;
	int sb;
	int ss;
    int pa;
	int pb;
    int ra;
	int rb;
	int rr;
    int rra;
	int rrb;
	int rrr;
    int total;
    double  disorder;
    char    *strategy_name;
    char    *complexity_class;
} t_bench;

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
void	complex(t_ps *ps, int lenght_a);

/* swap */
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* push */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* rotate */
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* reverse rotate */
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* helpers*/
void	assign_index(t_stack *stack_a);
void	stack_add_back(t_stack **stack, t_stack *new);
void	initialize_index(t_ps *ps);
int		stack_size(t_stack *stack);
int		get_chunk_count(int size);
int		chunk_finished(t_stack *a, int chunk_min, int chunk_max);
int		find_max_index(t_stack *stack);
int		position_of_index(t_stack *stack, int target_index);
int		position_of_next_chunk(t_stack *a, int min, int max);
double	compute_disorder(t_stack *a);
#endif