/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:44:56 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/07 16:52:36 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoi(const char *ptr)
{
	long int	res;
	long int	i;
	int			nbneg;

	i = 0;
	nbneg = 1;
	res = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == ' ')
		i++;
	if (ptr[i] == '-')
	{
		nbneg = -nbneg;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
		res = res * 10 + ptr[i++] - '0';
	res = res * nbneg;
	return (res);
}

int	ft_atoi_check(const char *ptr)
{
	int	res;
	int	i;
	int	nbneg;
	int	tmp;

	i = 0;
	nbneg = 1;
	res = 0;
	tmp = 0;
	if (ptr[i] == '-')
	{
		nbneg = -nbneg;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		tmp = res;
		res = res * 10 + ptr[i++] - '0';
		if (res < tmp)
			return (0);
	}
	return (1);
}
