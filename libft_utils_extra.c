/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:25:16 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/19 21:19:33 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_overflow_check(int sign)
{
	if (sign == 1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

long	ft_atol(const char *str)
{
	int		sign;
	int		sign_counter;
	int		i;
	long	num;

	sign = 1;
	num = 0;
	i = 0;
	sign_counter = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		sign_counter++;
	}
	while (ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	if (num < 0)
		return (ft_overflow_check(sign));
	if (sign_counter > 1)
		return (0);
	return (num * sign);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)s;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	max;

	max = -1;
	if (size && (count > (max / size)))
	{
		return (NULL);
	}
	new = malloc(count * size);
	if (!new)
	{
		return (0);
	}
	ft_bzero(new, count * size);
	return (new);
}
