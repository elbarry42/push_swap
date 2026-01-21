/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:35:51 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/21 10:59:27 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*adaptive(t_ps *ps, float disorder)
{
	if (disorder < 0.2)
	{
		simple(ps);
		return ("O(n²)");
	}
	else if (disorder < 0.5)
	{
		medium(ps);
		return ("O(n\u221An)");
	}
	else
	{
		complex(ps);
		return ("O(nlog(n))");
	}
}
