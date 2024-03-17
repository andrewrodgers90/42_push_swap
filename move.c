/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:10:18 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/19 17:40:07 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack **stack, t_stack *node, char name)
{
	while (*stack != node)
	{
		if (name == 'a')
		{
			if (node->above_median == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (node->above_median == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	rotate_down(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	rotate_up(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*b);
	if (cheap->above_median == 1 && cheap->target_node->above_median == 1)
		rotate_up(a, b, cheap);
	else if (cheap->above_median != 1 && cheap->target_node->above_median != 1)
		rotate_down(a, b, cheap);
	bring_to_top(a, cheap->target_node, 'a');
	bring_to_top(b, cheap, 'b');
	pa(a, b);
}
