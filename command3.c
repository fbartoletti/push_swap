/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:45:02 by fbartole          #+#    #+#             */
/*   Updated: 2024/09/04 16:45:12 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack **a, t_stack **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	reverserotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack **a)
{
	if (reverserotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **b)
{
	if (reverserotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **a, t_stack **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	reverserotate(a);
	reverserotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
