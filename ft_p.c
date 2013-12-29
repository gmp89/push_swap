/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:04:49 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/29 21:06:28 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_pa(t_data *data)
{
	int		i;
	int		tmp2;

	tmp2 = data->l_a[data->size_b - 1];
	data->size_a++;
	data->size_b--;
	i = data->size_a;
	while (i >= 0)
	{
		data->l_a[i] = data->l_a[i - 1];
		i--;
	}
	data->l_a[data->size_a] = tmp2;
	data->l_a[0] = data->l_b[0];
	i = 0;
	while (i < data->size_b)
	{
		data->l_b[i] = data->l_b[i + 1];
		i++;
	}
	ft_print_name(data, "pa");
	return (0);
}

int		ft_pb(t_data *data)
{
	int		i;
	int		tmp2;

	tmp2 = data->l_b[data->size_b - 1];
	data->size_a--;
	data->size_b++;
	i = data->size_b;
	while (i >= 0)
	{
		data->l_b[i] = data->l_b[i - 1];
		i--;
	}
	data->l_b[data->size_b] = tmp2;
	data->l_b[0] = data->l_a[0];
	i = 0;
	while (i <= data->size)
	{
		if (data->l_a[i + 1])
			data->l_a[i] = data->l_a[i + 1];
		i++;
	}
	ft_print_name(data, "pb");
	return (0);
}

int		ft_rr(t_data *data)
{
	ft_ra(data);
	ft_rb(data);
	ft_print_name(data, "rr");
	return (0);
}

int		ft_rrr(t_data *data)
{
	ft_rra(data);
	ft_rrb(data);
	ft_print_name(data, "rrr");
	return (0);
}
