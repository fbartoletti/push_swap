/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:04:02 by fbartole          #+#    #+#             */
/*   Updated: 2024/10/24 15:10:35 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->idx;
	max_bits = 0;
	while (head)
	{
		if (head->idx > max)
			max = head->idx;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	t_stack	*hd_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	hd_a = *a;
	size = ft_lstsize(hd_a);
	max_bits = ft_get_max(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			hd_a = *a;
			if (((hd_a->idx >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (ft_lstsize(*b) != 0)
			pa(a, b);
		i++;
	}
}
