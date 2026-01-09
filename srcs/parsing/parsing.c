/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:06:25 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/09 15:30:11 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	*is_error(int *array)
{
	write(2, "Error\n", 6);
	free(array);
	return (NULL);
}
int	*put_in_tmp_array(char **argv, int argc, int counter)
{
	int		*array;
	int		i;
	int		i_array;
	char	**array_alpha;

	i = 1;
	i_array = 0;
	array = malloc(sizeof(int) * (counter));
	if (!array)
		return (0);
	while (i < argc)
	{
		array_alpha = ft_split(argv[i], ' ');
		if (if_and_which_flags(argv[i]) == NULL)
			if (check_duplicate_number(array, array_alpha, &i_array) == 0)
				return (NULL);
		call_free(array_alpha);
		i++;
	}
	return (array);
}

int	*parsing(int argc, char **argv)
{
	char	*algo_type;
	int		counter;
	int		bench;
	int		*array;

	bench = 0;
	algo_type = NULL;
	array = NULL;
	if (argc == 1)
		return (1);
	algo_type = check_flags(argv, argc, &bench);
	counter = check_data(argc, argv);
	if (counter == 0 || algo_type == NULL)
		return (is_error(array));
	array = put_in_tmp_array(argv, argc, counter);
	if (array == NULL)
		return (is_error(array));
	return (array);
}
