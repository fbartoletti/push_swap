/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:03:59 by fbartole          #+#    #+#             */
/*   Updated: 2024/10/24 15:00:40 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_min(t_stack **stack, int v)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->idx;
	while (head->next)
	{
		head = head->next;
		if ((head->idx < min) && head->idx != v)
			min = head->idx;
	}
	return (min);
}

static void	sort_three(t_stack **a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *a;
	min = ft_get_min(a, -1);
	next_min = ft_get_min(a, min);
	if (head->idx == min && head->next->idx != next_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (head->idx == next_min && head->next->idx != min)
		rra(a);
	else if (head->next->idx == min && head->idx != next_min)
		ra(a);
	else if (head->idx != min && head->next->idx == next_min)
	{
		sa(a);
		rra(a);
	}
	else
		sa(a);
}

static void	sort_four(t_stack **a, t_stack **b)
{
	int	distance;

	if (ft_just_sorted(a))
		return ;
	distance = ft_get_distance(a, ft_get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (ft_just_sorted(a))
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int	distance;

	distance = ft_get_distance(a, ft_get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (ft_just_sorted(a))
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	ft_small_sort(t_stack **a, t_stack **b)
{
	int	size;

	if (ft_just_sorted(a) || ft_lstsize(*a) == 0
		|| ft_lstsize(*a) == 1)
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
