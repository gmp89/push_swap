/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:03:23 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/29 21:04:30 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_sa(t_data *data )
{
	int		tmp;

	if (!data->l_a[1])
		return (0);
	tmp = data->l_a[0];
	data->l_a[0] = data->l_a[1];
	data->l_a[1] = tmp;
	ft_print_name(data, "sa");
	return (0);
}

int		ft_sb(t_data *data)
{
	int		tmp;

	if (!data->l_b[1])
		return (0);
	tmp = data->l_b[0];
	data->l_b[0] = data->l_b[1];
	data->l_b[1] = tmp;
	ft_print_name(data, "sb");
	return (0);
}

int		ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
	ft_print_name(data, "ss");
	return (0);
}
