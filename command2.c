/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:43:47 by fbartole          #+#    #+#             */
/*   Updated: 2024/10/24 14:17:55 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	pa(t_stack **a, t_stack **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_stack **a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack **b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}
