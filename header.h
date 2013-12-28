/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:41:38 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/28 17:57:30 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/includes/libft.h"

typedef struct		s_data
{
	int				*l_a;
	int				*l_b;
	int				i;
	int				j;
}					t_data;

int		ft_make_list(t_data *data, char **av);
int		ft_sa(t_data *data );
int		ft_sb(t_data *data);
int		ft_ss(t_data *data);
int		ft_pa(t_data *data);
int		ft_pb(t_data *data);
int		ft_ra(t_data *data);
int		ft_rb(t_data *data);
int		ft_rr(t_data *data);
int		ft_rra(t_data *data);
int		ft_rrb(t_data *data);
void	ft_print_tab(t_data *data);

#endif
