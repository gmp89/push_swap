/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:34:47 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/29 22:44:05 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_make_list(t_data *data, char **av)
{
	int		size;

	size = 20;
	data->i = 1;
	data->j = 1;
	while (av[data->j] != 0)
		data->j++;
	data->size = data->j - 1;
	data->size_a = data->size;
	data->size_init_a = data->size_a;
	data->size_b = 0;
	data->l_a = (int *)malloc(sizeof(int) * data->size);
	data->l_b = (int *)malloc(sizeof(int) * data->size);
	data->j = 0;
	while (av[data->i] != 0)
	{
		data->l_a[data->j] = ft_atoi(av[data->i]);
		data->i++;
		data->j++;
	}
	return (0);
}

int		ft_sort(t_data *data)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (ft_sort_b_is_ok(data) || data->size_a > 1)
	{
		if (data->l_a[0] > data->l_a[1])
			ft_sa(data);
		else if (data->l_a[0] > data->l_a[data->size_a - 1])
			ft_rra(data);
		ft_pb(data);
		while (ft_sort_b_is_ok(data))
		{
			ft_sort_b(data);
			ft_pa(data);
		}
	}
	while (i < data->size_b)
		ft_pa(data);
	return (0);
}

int		ft_string_is_nb(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-' && str[1])
		i++;
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;

	data.k = 1;
	ac = ac;
	while (av[data.k])
	{
		if (ft_string_is_nb(av[data.k]) == -1)
		{
			ft_putstr("Error\n");
			return (0);
		}
		data.k++;
	}
	data.print = 1;
	ft_make_list(&data, av);
	if (ft_sort_is_ok(&data) == 0)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_sort(&data);
	ft_putchar('\n');
	free(data.l_a);
	free(data.l_b);
	return (0);
}
