/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:07:07 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/29 21:08:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_ra(t_data *data)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = data->l_a[0];
	while (i <= data->size_a)
	{
		data->l_a[i] = data->l_a[i + 1];
		i++;
	}
	data->l_a[data->size_a - 1] = tmp;
	ft_print_name(data, "ra");
	return (0);
}

int		ft_rb(t_data *data)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = data->l_b[0];
	while (i <= data->size_b)
	{
		data->l_b[i] = data->l_b[i + 1];
		i++;
	}
	data->l_b[data->size_b - 1] = tmp;
	ft_print_name(data, "rb");
	return (0);
}

int		ft_rra(t_data *data)
{
	int		i;
	int		tmp;

	i = data->size_a;
	tmp = data->l_a[data->size_a - 1];
	while (i >= 0)
	{
		data->l_a[i] = data->l_a[i - 1];
		i--;
	}
	data->l_a[0] = tmp;
	ft_print_name(data, "rra");
	return (0);
}

int		ft_rrb(t_data *data)
{
	int		i;
	int		tmp;

	i = data->size_b;
	tmp = data->l_b[data->size_b - 1];
	while (i >= 0)
	{
		data->l_b[i] = data->l_b[i - 1];
		i--;
	}
	data->l_b[0] = tmp;
	ft_print_name(data, "rrb");
	return (0);
}

void	ft_print_name(t_data *data, char *str)
{
	if (data->print == 1)
		data->print = 0;
	else
		ft_putstr(" ");
	ft_putstr(str);
}
