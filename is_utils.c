/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:43:52 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/19 21:14:19 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32 || c == '\0')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
