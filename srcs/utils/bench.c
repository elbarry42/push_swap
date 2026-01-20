/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:11:23 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/20 17:19:00 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_bench(t_ps *ps)
{
	ft_printf("[bench] disorder : %d,%d%\n", (int)ps->bench->disorder * 100,
		(int)ps->bench->disorder * 10000 - ((int)ps->bench->disorder * 100) * 100);
	ft_printf("[bench] total_ops : %d\n\n", ps->bench->total);

	ft_printf("[bench] sa:%d sb:%d ss:%d pa:%d pb:%d\n",
		ps->bench->sa, ps->bench->sb, ps->bench->ss, ps->bench->pa, ps->bench->pb);

	ft_printf("[bench] ra:%d rb:%d rr:%d rra:%d rrb:%d rrr:%d\n",
		ps->bench->ra, ps->bench->rb, ps->bench->rr, ps->bench->rra, ps->bench->rrb, ps->bench->rrr);
}

