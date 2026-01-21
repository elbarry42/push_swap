/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:35:51 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/21 11:39:55 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*adaptive(t_ps *ps, float disorder)
{
	if (disorder < 0.2)
	{
		if (disorder == 0)
			return ("O(n²)");
		simple(ps);
		return ("O(n²)");
	}
	else if (disorder < 0.5 && disorder > 0)
	{
		medium(ps);
		return ("O(n\u221An)");
	}
	else if (disorder > 0.5)
	{
		complex(ps);
		return ("O(nlog(n))");
	}
	else
		return ("");
}
