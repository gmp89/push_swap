/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:34:47 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/28 17:58:45 by gpetrov          ###   ########.fr       */
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
		data->i++;
		data->j++;

	}
	return (0);
}

int		ft_sa(t_data *data )
{
	int		tmp;

	if (!data->l_a[1])
		return (0);
	tmp = data->l_a[0];
	data->l_a[0] = data->l_a[1];
	data->l_a[1] = tmp;
	ft_putstr("sa ");
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
	ft_putstr("sb ");
	return (0);
}

int		ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
	ft_putstr("ss ");
	return (0);
}

int		ft_pa(t_data *data)
{
	int		i;

	i = 0;
	if (!data->l_b[0])
		return (0);
	data->l_a[0] = data->l_b[0];
	while (data->l_b[i])
	{
		data->l_b[i] = data->l_b[i + 1];
		i++;
	}
	data->l_b[i] = 0;
	ft_putstr("pa ");
	return (0);
}

int		ft_pb(t_data *data)
{
	int		i;

	i = 0;
	if (!data->l_a[0])
		return (0);
	data->l_b[0] = data->l_a[0];
	while (data->l_a[i])
	{
		data->l_a[i] = data->l_a[i + 1];
		i++;
	}
	data->l_a[i] = 0;
	ft_putstr("pb ");
	return (0);
}

int		ft_ra(t_data *data)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = data->l_a[0];
	while (data->l_a[i])
	{
		data->l_a[i] = data->l_a[i + 1];
		i++;
	}
	data->l_a[i - 1] = tmp;
	ft_putstr("ra ");
	return (0);
}

int		ft_rb(t_data *data)
{
	int		i;
	int		tmp;

	i = 0;
	if (!data->l_b[0])
		return (0);
	while (data->l_b[i])
	{
		data->l_b[i] = data->l_b[i + 1];
		i++;
	}
	data->l_b[i - 1] = tmp;
	ft_putstr("rb ");
	return (0);
}

int		ft_rr(t_data *data)
{
	ft_ra(data);
	ft_rb(data);
	ft_putstr("rr ");
	return (0);
}

int		ft_rra(t_data *data)
{
	int		i;
	int		tmp;

	i = 0;
	while (data->l_a[i])
		i++;
	tmp = data->l_a[i - 1];
	i--;
	while (data->l_a[i])
	{
		data->l_a[i] = data->l_a[i - 1];
		i--;
	}
	data->l_a[0] = tmp;
	ft_putstr("rra ");
	return (0);
}

int		ft_rrb(t_data *data)
{
	int		i;
	int		tmp;

	i = 0;
	while (data->l_b[i])
		i++;
	tmp = data->l_b[i - 1];
	i--;
	while (data->l_b[i])
	{
		data->l_b[i] = data->l_b[i - 1];
		i--;
	}
	data->l_b[0] = tmp;
	ft_putstr("rrb ");
	return (0);
}

int		ft_rrr(t_data *data)
{
	ft_rra(data);
	ft_rrb(data);
	ft_putstr("rrr ");
	return (0);
}

void	ft_print_tab(t_data *data)
{
	int		i;

	i = 0;
	ft_putstr("l_a : ");
	while (data->l_a[i])
	{
		ft_putnbr(data->l_a[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	i = 0;
	ft_putstr("l_b : ");
	while (data->l_b[i])
	{
		ft_putnbr(data->l_b[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	t_data		data;

	if (ac >= 2)
	{
		ft_make_list(&data, av);
		ft_rra(&data);
		ft_print_tab(&data);
	}
	return (0);
}
