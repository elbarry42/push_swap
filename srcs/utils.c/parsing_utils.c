/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:23:13 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/08 15:14:11 by larchimb         ###   ########.fr       */
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

int	check_number(char **array)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	nbr = 0;
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
		nbr = ft_atoi(array[i]);
		i++;
	}
	call_free(array);
	return (1);
}

int	check_data(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (which_flags(argv[i]) == NULL)
		{
			if (check_number(ft_split(argv[i], ' ')) == 0)
				return (0);
			i++;
		}
		else
		{
			if (i == 2 && check_number(ft_split(argv[i - 1], ' ')) == 1)
				return (0);
			else if (i == argc - 2 && check_number(ft_split(argv[i + 1], ' ')) == 1)
				return (0);
			else if (argc >= 4 && i > 2 && i < argc - 2)
				return(0);
			i++;
		}
	}
	return (1);
}
