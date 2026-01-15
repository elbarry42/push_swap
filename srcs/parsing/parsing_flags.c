/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:00:22 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/15 15:25:16 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*if_and_which_flags(char *str)
{
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return ("adaptive");
	else if (ft_strncmp(str, "--simple", 9) == 0)
		return ("simple");
	else if (ft_strncmp(str, "--medium", 9) == 0)
		return ("medium");
	else if (ft_strncmp(str, "--complex", 10) == 0)
		return ("complex");
	else if (ft_strncmp(str, "--bench", 8) == 0)
		return ("bench");
	else
		return (NULL);
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
		else if (if_and_which_flags(argv[i]) != NULL)
		{
			algo_type = if_and_which_flags(argv[i]);
			algo += 1;
			if (check_flag_placement(argv, argc, i) == 0)
				return (NULL);
		}
		i += 1;
	}
	if (*bench >= 2 || algo >= 2)
		return (NULL);
	if (algo_type == NULL)
		algo_type = "adaptive";
	return (algo_type);
}
