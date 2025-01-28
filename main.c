/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:30:36 by barto             #+#    #+#             */
/*   Updated: 2024/10/24 15:04:13 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_init_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*n;
	char	**arg;
	int		i;

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
		n = ft_lstnew(ft_atoi(arg[i]));
		ft_lstadd_back(stack, n);
		i++;
	}
	ft_stack_idx(stack);
	if (ac == 2)
		ft_free(arg);
}

static void	ft_sort_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) <= 5)
		ft_small_sort(a, b);
	else
		ft_big_sort(a, b);
}

// void	ft_print_stack(t_stack **stack)
// {
// 	t_stack	*current;

// 	current = *stack;
// 	printf("%s", "numeri sortati: ");
// 	while (current != NULL)
// 	{
// 		printf("%d", current->value);
// 		printf("%c", ' ');
// 		current = current->next;
// 	}
// }
//ft_print_stack(a);

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	if (ac < 2)
		return (-1);
	ft_check_arg(ac, av);
	a = (t_stack **)malloc(sizeof(t_stack));
	b = (t_stack **)malloc(sizeof(t_stack));
	*a = NULL;
	*b = NULL;
	ft_init_stack(a, ac, av);
	if (ft_just_sorted(a))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		return (0);
	}
	ft_sort_stack(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
