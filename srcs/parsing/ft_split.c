/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:33:47 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/15 15:25:31 by larchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			counter++;
			if (!s[i])
				return (counter);
		}
		i++;
	}
	return (counter);
}

static	char	**free_array(char **array, int i_array)
{
	while (i_array >= 0)
		free(array[i_array--]);
	free(array);
	return (NULL);
}

static	char	*put_word_in_array(char const *s, char c, int *i)
{
	char	*ptr;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	*i += len;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		i_array;
	char	**array;

	i = 0;
	i_array = 0;
	if (!s)
		return (NULL);
	array = ft_calloc((count_words((char const *)s, c) + 1), sizeof(char *));
	if (!array)
		return (array = NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			array[i_array] = put_word_in_array(s + i, c, &i);
			if (array[i_array] == NULL)
				return (free_array(array, i_array));
			i_array++;
		}
		else
			i++;
	}
	array[i_array] = NULL;
	return (array);
}
