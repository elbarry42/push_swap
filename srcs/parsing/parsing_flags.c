/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:00:22 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/20 18:20:06 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*if_and_which_flags(char *str)
{
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return ("Adaptive");
	else if (ft_strncmp(str, "--simple", 9) == 0)
		return ("Simple");
	else if (ft_strncmp(str, "--medium", 9) == 0)
		return ("Medium");
	else if (ft_strncmp(str, "--complex", 10) == 0)
		return ("Complex");
	else if (ft_strncmp(str, "--bench", 8) == 0)
		return ("bench");
	else
		return (NULL);
}

int	check_flag_placement(char **argv, int argc, int i)
{
	if (i == 2 && check_number(ft_split(argv[i - 1], ' '), &i) == 1)
		return (0);
	else if (argc >= 4 && i == argc - 2
		&& check_number(ft_split(argv[i + 1], ' '), &i) == 1)
		return (0);
	else if (argc >= 4 && i > 2 && i < argc - 2)
		return (0);
	else
		return (1);
}

char	*finalcheck_flags(int *bench, int algo, char *algo_type)
{
	if (*bench >= 2 || algo >= 2)
		return (NULL);
	if (algo_type == NULL)
		algo_type = "Adaptive";
	return (algo_type);
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
		if (if_and_which_flags(argv[i]) != NULL)
		{
			if (ft_strncmp(if_and_which_flags(argv[i]), "bench", 7) == 0)
				*bench = *bench + 1;
			else
			{
				algo_type = if_and_which_flags(argv[i]);
				algo += 1;
			}
			if (check_flag_placement(argv, argc, i) == 0)
				return (NULL);
		}
		i += 1;
	}
	return (finalcheck_flags(bench, algo, algo_type));
}
