/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:24:00 by barto             #+#    #+#             */
/*   Updated: 2024/09/04 16:37:18 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	ft_putendl_fd(s, 1);
	exit(0);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
		free(s[i--]);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
