/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:35:51 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/20 14:19:02 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_ps *ps, float disorder)
{
	if (disorder < 0.2)
		simple(ps);
	else if (disorder < 0.5)
		medium(ps);
	else
		complex(ps);
}
