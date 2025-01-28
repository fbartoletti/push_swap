/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:34:18 by barto             #+#    #+#             */
/*   Updated: 2024/09/04 16:37:30 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdup(int n, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *n)
{
	int	i;

	i = 0;
	if (n[0] == '-')
		i++;
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_arg(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**arg;

	i = 0;
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
	{
		i = 1;
		arg = av;
	}
	while (arg[i])
	{
		tmp = ft_atoi(arg[i]);
		if (!ft_isnum(arg[i]))
			ft_error("Error");
		if (ft_isdup(tmp, arg, i))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
	if (ac == 2)
		ft_free(arg);
}
