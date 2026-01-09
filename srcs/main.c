/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbarry <elbarry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:55:57 by elbarry           #+#    #+#             */
/*   Updated: 2026/01/08 19:09:03 by elbarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_ps    ps;
    int     *values;
    int     i;
    int     count;


    if (argc < 2)
        return (0);
    values = parsing(argc, argv);
    if (!values)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    ps.stack_a = NULL;
    ps.stack_b = NULL;
    count = argc - 1;
    i = 0;
    while (i < count)
    {
        stack_add_back(&ps.stack_a, stack_new(values[i]));
        i++;
    }
    free(values);
    return (0);
}
