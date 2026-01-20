/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larchimb <larchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:44:56 by larchimb          #+#    #+#             */
/*   Updated: 2026/01/19 16:21:50 by larchimb         ###   ########.fr       */
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
	unsigned int	res;
	int				i;
	int				nbneg;
	unsigned int	tmp;

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
		res = res * 10 + ptr[i++] - '0';
		if (nbneg > 0 && res > 2147483647)
			return (0);
		else if (nbneg < 0 && res > 2147483648)
			return (0);
	}
	return (1);
}
