/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbartole <fbartole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:29:16 by barto             #+#    #+#             */
/*   Updated: 2024/10/24 14:15:30 by fbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Srackt
typedef struct s_stack
{
	int				value;
	int				idx;
	struct s_stack	*next;
}				t_stack;

/* main */
int		main(int ac, char **av);
/* check_args */
void	ft_check_arg(int ac, char **av);
/* free */
void	ft_error(char *s);
void	ft_free(char **s);
void	ft_free_stack(t_stack **stack);
/* index */
void	ft_stack_idx(t_stack **stack);
/* small_sort */
void	ft_small_sort(t_stack **a, t_stack **b);
/* big_sort */
void	ft_big_sort(t_stack **a, t_stack **b);
/* command */
int		swap(t_stack **stack);
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);
int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		rotate(t_stack **stack);
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		reverserotate(t_stack **stack);
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);
/* t_stack */
t_stack	*ft_lstnew(int value);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *head);
void	printlist(t_stack *head);
/* utils */
int		ft_just_sorted(t_stack **stack);
int		ft_get_distance(t_stack **stack, int idx);
void	make_top(t_stack **stack, int distance);

#endif
