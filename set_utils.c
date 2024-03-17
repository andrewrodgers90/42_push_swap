/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:37:18 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/19 17:40:35 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (NULL == stack)
		return ;
	median = (stack_size(stack) / 2);
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_size(a);
	b_len = stack_size(b);
	while (b)
	{
		b->push_cost = b->index;
		if (b->above_median == 0)
			b->push_cost = b_len - (b->index);
		if (b->target_node->above_median == 1)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += a_len - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long		best_value;
	t_stack		*match_node;

	if (NULL == b)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_value)
		{
			best_value = b->push_cost;
			match_node = b;
		}
		b = b->next;
	}
	match_node->cheapest = 1;
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack		*a_current;
	t_stack		*target_node;
	long		best_match;

	while (b)
	{
		best_match = LONG_MAX;
		a_current = a;
		while (a_current)
		{
			if (a_current->data > b->data && a_current->data < best_match)
			{
				best_match = a_current->data;
				target_node = a_current;
			}
			a_current = a_current->next;
		}
		if (LONG_MAX == best_match)
			b->target_node = get_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
