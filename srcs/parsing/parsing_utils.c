/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:23:13 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/09 11:58:39 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
		if (which_flags(argv[i]) == NULL)
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

int	check_duplicate_number(int *array, int value, int index)
{
	while (index >= 1)
	{
		if (array[--index] == value)
			return (0);
	}
	return (1);
}

int	*put_in_tmp_array(char **argv, int argc, int counter)
{
	int		*array;
	int		i;
	int		j;
	int		i_array;
	char	**array_alpha;

	i = 1;
	i_array = 0;
	array = malloc(sizeof(int) * (counter));
	if (!array)
		return (0);
	while (i < argc)
	{
		j = 0;
		array_alpha = ft_split(argv[i], ' ');
		if (which_flags(argv[i]) == NULL)
		{
			while (array_alpha[j])
			{
				array[i_array] = ft_atoi(array_alpha[j]);
				if (check_duplicate_number(array, ft_atoi(array_alpha[j++]), i_array++) == 0)
				{
					call_free(array_alpha);
					free(array);
					return (NULL);
				}
			}
		}
		call_free(array_alpha);
		i++;
	}
	return (array);
}
