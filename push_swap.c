/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:03:45 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/21 13:55:26 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*highest_value;

	highest_value = get_highest(*a);
	if (highest_value == *a)
		ra(a);
	else if (highest_value == (*a)->next)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		stack_len;
	t_stack	*smallest;

	stack_len = stack_size(*a);
	while (stack_len-- > 3)
	{
		pb(b, a);
	}
	sort_three(a);
	while (*b)
	{
		set_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_index(*a);
	smallest = get_smallest(*a);
	if (smallest->above_median == 1)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}

void	create_stack(t_stack **stack, char **values)
{
	int		i;
	long	nbr;

	i = 0;
	while (values[i] != NULL)
	{
		if (check_syntax(values[i]) == 1)
			free_all(stack, values, 1);
		nbr = ft_atol(values[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_all(stack, values, 1);
		if (check_duplicates(*stack, (int)nbr) == 1)
			free_all(stack, values, 1);
		if (check_int(values[i]) == 1)
			free_all(stack, values, 1);
		add_stack_member(stack, (int)nbr);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**values;

	a_stack = NULL;
	b_stack = NULL;
	handle_args(ac, av);
	values = parse_args(ac, av);
	create_stack(&a_stack, values);
	if (stack_sorted(a_stack) == 0)
	{
		if (stack_size(a_stack) == 2)
			sa(&a_stack);
		else if (stack_size(a_stack) == 3)
			sort_three(&a_stack);
		else
			push_swap(&a_stack, &b_stack);
	}
	free_all(&a_stack, values, 0);
	return (0);
}
