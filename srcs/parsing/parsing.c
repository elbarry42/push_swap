/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:06:25 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/08 15:26:13 by larchimb         ###   ########.fr       */
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

char	*check_flags_end(char **argv, int argc, int *bench, int *algo)
{
	char	*algo_type;
	int		i;

	algo_type = NULL;
	i = argc - 1;
	while (which_flags(argv[i]) != NULL && i > argc - 3)
	{
		if (ft_strncmp(argv[i], "--bench", 7) == 0)
		{
			*bench = *bench + 1;
		}
		else if (which_flags(argv[i]) != NULL)
		{
			algo_type = which_flags(argv[i]);
			*algo += 1;
		}
		i--;
	}
	return (algo_type);
}

char	*check_flags_begin(char **argv, int *i, int *bench, int *algo)
{
	char	*algo_type;

	algo_type = NULL;
	while (which_flags(argv[*i]) != NULL && *i < 3)
	{
		if (ft_strncmp(argv[*i], "--bench", 7) == 0)
		{
			*bench = *bench + 1;
		}
		else if (which_flags(argv[*i]) != NULL)
		{
			algo_type = which_flags(argv[*i]);
			*algo += 1;
		}
		*i += 1;
	}
	return (algo_type);
}

char	*check_flags(char **argv, int *i, int *bench, int argc)
{
	int		algo;
	char	*algo_type_begin;
	char	*algo_type_end;

	algo = 0;
	algo_type_begin = check_flags_begin(argv, i, bench, &algo);
	algo_type_end = check_flags_end(argv, argc, bench, &algo);
	if (*bench >= 2 || algo >= 2)
		return (NULL);
	if (algo_type_begin == NULL && algo_type_end == NULL)
		return("adaptive");
	if (algo_type_begin == NULL)
		return(algo_type_end);
	else
		return(algo_type_begin);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*algo_type;
	int		bench;

	i = 1;
	bench = 0;
	algo_type = NULL;
	if (argc == 1)
		return (1);
	algo_type = check_flags(argv, &i, &bench, argc);
	if (check_data(argc, argv) == 0 || algo_type == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_printf("%s\nbench = %d", algo_type, bench);
}
