/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:01:17 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/19 17:41:18 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	if (NULL == stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	stack_sorted(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*stack_last(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_stack_member(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (NULL == stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = value;
	if (NULL == *stack)
	{
		*stack = new_node;
		new_node->previous = NULL;
	}
	else
	{
		last_node = stack_last(*stack);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}
