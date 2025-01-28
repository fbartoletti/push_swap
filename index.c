/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:39:17 by barto             #+#    #+#             */
/*   Updated: 2024/09/04 16:37:03 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		the_min;

	min = NULL;
	the_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->idx == -1) && (!the_min || head->value < min->value))
			{
				min = head;
				the_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_stack_idx(t_stack **stack)
{
	t_stack	*head;
	int		idx;

	idx = 0;
	head = ft_next_min(stack);
	while (head)
	{
		head->idx = idx++;
		head = ft_next_min(stack);
	}
}
