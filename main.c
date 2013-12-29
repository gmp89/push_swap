/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:34:47 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/29 18:58:39 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <time.h> /* test */

int rand_int(int nb, int a, int b)
{
	return ((nb % (b - a)) + a);
}

int		ft_make_list(t_data *data, char **av)
{
	int		size;

	size = 20;
	data->i = 1;
	data->j = 1;
	while (av[data->j] != 0)
		data->j++;
	srand(time(NULL)); /* test */
	data->j = size; /* test */
	data->size = data->j - 1;
	data->size_a = data->size;
	data->size_init_a = data->size_a;
	data->size_b = 0;
	data->l_a = (int *)malloc(sizeof(int) * data->size);
	data->l_b = (int *)malloc(sizeof(int) * data->size);
	data->j = 0;
/*	while (av[data->i] != 0)*/
	while (data->j < size) /* test */
	{
		/*	data->l_a[data->j] = ft_atoi(av[data->i]);*/
		data->l_a[data->j] = rand_int(rand(), -20, 200); /* test */
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
	ft_putstr("i : ");
	ft_putnbr(i);
	ft_putstr(", size : ");
	ft_putnbr(data->size_b);
	ft_putstr("\n");
	while (i < data->size_b)
	{
		ft_putstr("i : ");
		ft_putnbr(i);
		ft_putstr(", size : ");
		ft_putnbr(data->size_b);
		ft_putstr("\n");
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
	while (i <= data->size_a)
	{
		data->l_a[i] = data->l_a[i + 1];
		i++;
	}
	data->l_a[data->size_a - 1] = tmp;
	ft_putstr("ra ");
	ft_putchar('\n');
	ft_print_tab(data);
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
	ft_putstr("rb ");
	ft_putchar('\n');
	ft_print_tab(data);
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

	i = data->size_a;
	tmp = data->l_a[data->size_a - 1];
	while (i >= 0)
	{
		data->l_a[i] = data->l_a[i - 1];
		i--;
	}
	data->l_a[0] = tmp;
	ft_putstr("rra ");
	ft_putchar('\n');
	ft_print_tab(data);
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
	ft_putstr("rrb ");
	ft_putchar('\n');
	ft_print_tab(data);
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
		{
			ft_putstr("tab b non trie \n");
			return (-1);
		}
	}
	ft_putstr("tab b trie \n");
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


int		ft_sort(t_data *data)
{
	int		max;
	int		j;
	int		i;

	i = 0;
	j = 0;
	max = ft_count(data);
	ft_print_tab(data);
	while (ft_sort_b_is_ok(data) || data->size_a > 1)
	{
		ft_print_tab(data);
		/* usleep(400000); */
		if (data->l_a[0] > data->l_a[1])
			ft_sa(data);
		else if (data->l_a[0] > data->l_a[data->size_a])
			ft_rra(data);
		ft_pb(data);
		while (ft_sort_b_is_ok(data))
		{
			ft_sort_b(data);
			ft_pa(data);
		}
		ft_print_tab(data);
	}
	ft_putstr("fin de tri\n");
	while (i < data->size_b)
	{
		ft_putstr("t : i : ");
		ft_putnbr(i);
		ft_putstr(", size : ");
		ft_putnbr(data->size_b);
		ft_putstr("\n");
		ft_pa(data);
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
		ft_sort(&data);
		/* ft_pb(&data); */
		/* ft_pb(&data); */
		/* ft_pb(&data); */
		/* ft_pb(&data); */
		/* ft_pa(&data); */
		/* ft_pa(&data); */
		/* ft_pa(&data); */
		/* ft_pa(&data); */
		/* ft_rra(&data); */
		/* ft_rra(&data); */
		/* ft_ra(&data); */
		/* ft_putchar('\n'); */
		ft_putstr("fin de programme :\n");
		ft_print_tab(&data);
	}
	return (0);
}
