/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:27:47 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/21 13:55:15 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*handle_str(char *s1, char *s2)
{
	ft_strcat(s1, " ");
	ft_strcat(s1, s2);
	return (s1);
}

int	handle_args(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while (av[i] != NULL)
	{
		if (!av[i][0])
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (0);
}

char	**parse_args(int ac, char **av)
{
	char	*string;
	char	**values;
	int		i;
	int		len;

	len = 0;
	i = 1;
	while (i < ac)
		len += ft_strlen(av[i++]);
	string = (char *)malloc(sizeof(char) * (len + 1 + (ac - 1)));
	string = ft_strcpy(string, av[1]);
	i = 2;
	while (av[i] != NULL)
	{
		if (!av[i][0])
			free(string);
		else
			handle_str(string, av[i]);
		i++;
	}
	check_syntax(string);
	values = ft_split(string, ' ');
	free(string);
	return (values);
}
