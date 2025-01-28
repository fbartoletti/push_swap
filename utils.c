/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:28:34 by fbartole          #+#    #+#             */
/*   Updated: 2024/09/04 16:38:27 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_just_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_get_distance(t_stack **stack, int idx)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->idx == idx)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	make_top(t_stack **stack, int distance)
{
	t_stack	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ft_lstsize(head) - distance;
	if (distance <= (ft_lstsize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}
