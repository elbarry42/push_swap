/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:06:25 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/22 14:10:30 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_pars	*is_error(t_pars *values, char **argv)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	free(values);
	if (!argv)
		return (NULL);
	while (argv[i])
		free(argv[i++]);
	free(argv);
	return (NULL);
}

static	char	**clean_argv(int *argc, char **argv)
{
	int		i;
	char	*ptr;
	char	*tmp;
	char	**array;

	i = 0;
	ptr = ft_strjoin(argv[i++], " ");
	while (i < *argc)
	{
		tmp = ptr;
		ptr = ft_strjoin(ptr, argv[i++]);
		free(tmp);
		if (!ptr)
			return (NULL);
	}
	*argc = count_words(ptr, ' ');
	array = ft_split(ptr, ' ');
	free(ptr);
	return (array);
}

static	int	*put_in_tmp_array(char **argv, int argc, int counter)
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
	argv = clean_argv(&argc, argv);
	if (!argv)
		return (is_error(values, argv));
	values->algo_type = check_flags(argv, argc, &values->bench);
	values->counter = check_data(argc, argv);
	if (values->counter == 0 || values->algo_type == NULL)
		return (is_error(values, argv));
	values->array = put_in_tmp_array(argv, argc, values->counter);
	if (values->array == NULL)
		return (is_error(values, argv));
	call_free(argv);
	return (values);
}
