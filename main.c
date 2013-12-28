/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:34:47 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/28 23:39:48 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_make_list(t_data *data, char **av)
{
	data->i = 1;
	data->j = 1;
	while (av[data->j] != 0)
		data->j++;
	data->size = data->j - 1;
	data->size_a = data->size;
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
	while (i <= data->size_b)
	{
		data->l_b[i] = data->l_b[i + 1];
		i++;
	}
	ft_putstr("pa ");
	ft_putchar('\n');
	ft_print_tab(data);
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
	ft_putstr("pb ");
	ft_putchar('\n');
	ft_print_tab(data);
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

int		ft_count(t_data *data)
{
	int		i;

	i = 0;
	while (data->l_a[i])
		i++;
	return (i - 1);
}

int		ft_sort_is_ok(t_data *data)
{
	int		i;

	i = data->size;
	while (i >= 0)
	{
		if (data->l_a[i - 1] && data->l_a[i - 1] < data->l_a[i])
			i--;
		else
			return (-1);
	}
	return (0);
}

int		ft_sort(t_data *data)
{
	int		max;
	int		j;
	int		i;

	i = 0;
	j = 0;
	max = ft_count(data);
	while (ft_sort_is_ok(data) != 0)
	{
		if (data->l_a[0] > data->l_a[1] || data->l_a[0] > data->l_a[max])
		{
			if (data->l_a[0] > data->l_a[1])
				ft_sa(data);
			if (data->l_a[0] > data->l_a[max])
				ft_rra(data);
		}
		else if (data->l_a[0] < data->l_a[1] && data->l_a[0] < data->l_a[max] && ft_sort_is_ok(data) == -1)
		{
			ft_pb(data);
			if (data->l_b[1] && data->l_b[0] < data->l_b[1])
				ft_sb(data);
		}
		else
		{
			while (data->l_a[i])
			{
				ft_pa(data);
				i++;
			}
		}
		ft_print_tab(data);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;

	if (ac >= 2)
	{
		ft_make_list(&data, av);
		if (ft_sort_is_ok(&data) == 0)
		{
			ft_print_tab(&data);
			return (0);
		}
		/* ft_sort(&data); */
		ft_pb(&data);
		ft_pb(&data);
		ft_pb(&data);
		ft_pb(&data);
		ft_pa(&data);
		ft_pa(&data);
		ft_pa(&data);
		ft_pa(&data);
		ft_putchar('\n');
		ft_print_tab(&data);
	}
	return (0);
}
