/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:34:47 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/27 20:07:29 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_make_list(t_data *data, char **av)
{
	data->i = 1;
	data->j = 1;
	while (av[data->j] != 0)
		data->j++;
	data->l_a = (int *)malloc(sizeof(int) * data->j) + 1;
	data->l_b = (int *)malloc(sizeof(int) * data->j) + 1;
	data->j = 0;
	while (av[data->i] != 0)
	{
		data->l_a[data->j] = ft_atoi(av[data->i]);
		ft_putnbr(data->l_a[data->j]);
		ft_putchar('\n');
		data->i++;
		data->j++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;
	int			k;

	if (ac)
		k = 0;
	ft_make_list(&data, av);
	return (0);
}
