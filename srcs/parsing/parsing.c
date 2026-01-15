/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:06:25 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/15 18:01:30 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_pars	*is_error(t_pars *values)
{
	write(2, "Error\n", 6);
	free(values);
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
		return (NULL);
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

t_pars	*parsing(int argc, char **argv)
{
	t_pars	*values;

	if (argc == 1)
		return (NULL);
	values = malloc(sizeof(t_pars));
	if (!values)
		return (NULL);
	values->bench = 0;
	values->algo_type = NULL;
	values->array = NULL;
	values->algo_type = check_flags(argv, argc, &values->bench);
	values->counter = check_data(argc, argv);
	if (values->counter == 0 || values->algo_type == NULL)
		return (is_error(values));
	values->array = put_in_tmp_array(argv, argc, values->counter);
	if (values->array == NULL)
		return (is_error(values));
	return (values);
}
