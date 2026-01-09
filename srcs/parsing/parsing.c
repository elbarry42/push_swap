/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:06:25 by larchimb          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/09 12:00:22 by larchimb         ###   ########.fr       */
=======
/*   Updated: 2026/01/08 18:20:00 by elbarry          ###   ########.fr       */
>>>>>>> b483c31db3cfd2e5a42b994f9a2398e92777cd6e
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*which_flags(char *str)
{
	if (ft_strncmp(str, "--adaptive", 10) == 0)
		return ("adaptive");
	else if (ft_strncmp(str, "--simple", 8) == 0)
		return ("simple");
	else if (ft_strncmp(str, "--medium", 8) == 0)
		return ("medium");
	else if (ft_strncmp(str, "--complex", 9) == 0)
		return ("complex");
	else if (ft_strncmp(str, "--bench", 7) == 0)
		return ("bench");
	else
		return (NULL);
}

char	*flags_validation(char *algo_type, int algo, int bench)
{
	if (bench >= 2 || algo >= 2)
		return (NULL);
	if (algo_type == NULL)
		algo_type = "adaptive";
	return (algo_type);
}

int	check_flag_placement(char **argv, int argc, int i)
{
	if (i == 2 && check_number(ft_split(argv[i - 1], ' '), &i) == 1)
		return (0);
	else if (i == argc - 2 && check_number(ft_split(argv[i + 1], ' '), &i) == 1)
		return (0);
	else if (argc >= 4 && i > 2 && i < argc - 2)
		return (0);
	else
		return (1);
}

char	*check_flags(char **argv, int argc, int *bench)
{
	int		i;
	int		algo;
	char	*algo_type;

	i = 1;
	algo = 0;
	algo_type = NULL;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 7) == 0)
			*bench = *bench + 1;
		else if (which_flags(argv[i]) != NULL)
		{
			algo_type = which_flags(argv[i]);
			algo += 1;
			if (check_flag_placement(argv, argc, i) == 0)
				return (NULL);
		}
		i += 1;
	}
	return (flags_validation(algo_type, algo, *bench));
}

int	parsing(int argc, char **argv)
{
	int		i;
	char	*algo_type;
	int		counter;
	int		bench;
	int		*test;

	i = 0;
	bench = 0;
	algo_type = NULL;
	if (argc == 1)
		return (1);
	algo_type = check_flags(argv, argc, &bench);
	counter = check_data(argc, argv);
	test = put_in_tmp_array(argv, argc, counter);
	if (counter == 0 || algo_type == NULL || test == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < counter)
		ft_printf("%d\n", test[i++]);
	ft_printf("%s\nbench : %d", algo_type, bench);
	free(test);
	ft_printf("%s\nbench = %d", algo_type, bench);
	return(1);
}
