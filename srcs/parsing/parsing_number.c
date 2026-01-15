/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:23:13 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/15 15:25:10 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	call_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (0);
}

int	check_number(char **array, int *counter)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '-' || array[i][j] == '+')
				j++;
			if (ft_isdigit(array[i][j]) == 0)
				return (call_free(array));
			j++;
		}
		if (ft_atoi_check(array[i]) == 0)
			return (call_free(array));
		*counter += 1;
		i++;
	}
	call_free(array);
	return (1);
}

int	check_data(int argc, char **argv)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (i < argc)
	{
		if (if_and_which_flags(argv[i]) == NULL)
		{
			if (check_number(ft_split(argv[i], ' '), &counter) == 0)
				return (0);
			i++;
		}
		else
			i++;
	}
	return (counter);
}

int	check_duplicate_number(int *array, char **array_alpha, int *i_array)
{
	int	index;
	int	j;

	index = *i_array;
	j = 0;
	while (array_alpha[j])
	{
		array[*i_array] = ft_atoi(array_alpha[j]);
		while (index >= 1)
		{
			if (array[--index] == ft_atoi(array_alpha[j]))
			{
				call_free(array_alpha);
				free(array);
				return (0);
			}
		}
		*i_array += 1;
		index = *i_array;
		j++;
	}
	return (1);
}
