/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:08:38 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/29 21:09:38 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_print_tab(t_data *data)
{
	int		i;

	i = 0;
	ft_putstr("l_a : ");
	while (i < data->size_a)
	{
		ft_putnbr(data->l_a[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	i = 0;
	ft_putstr("l_b : ");
	while (i < data->size_b)
	{
		ft_putnbr(data->l_b[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		ft_sort_is_ok(t_data *data)
{
	int		i;

	i = data->size_a - 1;
	while (i >= 0)
	{
		if (data->l_a[i - 1] < data->l_a[i])
			i--;
		else
			return (-1);
	}
	if (data->size_a != data->size_init_a)
		return (-1);
	return (0);
}

int		ft_sort_b_is_ok(t_data *data)
{
	int		i;

	i = data->size_b - 1;
	while (i > 0)
	{
		if (data->l_b[i - 1] > data->l_b[i])
			i--;
		else
			return (-1);
	}
	return (0);
}

int		ft_sort_is(t_data *data)
{
	int		i;

	i = data->size_a - 1;
	while (i >= 0)
	{
		if (data->l_a[i - 1] < data->l_a[i])
			i--;
		else
			return (-1);
	}
	return (0);
}

void	ft_sort_b(t_data *data)
{
	if (data->size_b == 1)
		return ;
	if (data->l_b[data->size_b] && data->l_b[0] < data->l_b[data->size_b - 1])
		ft_rb(data);
	else if (data->l_b[1] && data->l_b[0] < data->l_b[1])
		ft_sb(data);
}
