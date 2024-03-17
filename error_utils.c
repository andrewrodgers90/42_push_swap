/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:24:25 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/21 13:55:21 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	int		len;
	int		i;
	int		flag;
	int		compare;
	char	*num;

	len = 0;
	i = 0;
	num = "2147483648";
	compare = 0;
	while (ft_isspace(str[i]) || ft_issign(str[i]))
		i++;
	flag = i;
	while (ft_isdigit(str[i++]))
		len++;
	if (len > 10)
		return (1);
	if (len == 10)
		compare = ft_strncmp(num, &str[flag], 10);
	if (compare < 0)
		return (1);
	return (0);
}

int	check_syntax(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (!str[0])
		free(str);
	len = ft_strlen(str);
	if (len == 1 && (!(ft_isdigit(str[i]))))
		return (1);
	if (ft_issign(str[0]) && (!(ft_isdigit(str[1]))))
		return (1);
	while (str[i])
	{
		if (!(ft_issign(str[i]) || ft_isdigit(str[i]) || ft_isspace(str[i])))
			return (1);
		if (ft_isdigit(str[i]) && ft_issign(str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicates(t_stack *stack, int nbr)
{
	if (NULL == stack)
		return (0);
	while (stack)
	{
		if (stack->data == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
