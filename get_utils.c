/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:44:20 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/19 21:14:11 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_highest(t_stack *stack)
{
	t_stack	*max_node;
	int		max;

	if (NULL == stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

size_t	get_biggest(t_stack *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

t_stack	*get_smallest(t_stack *stack)
{
	long	min;
	t_stack	*smallest;

	if (NULL == stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
