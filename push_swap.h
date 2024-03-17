/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:06:14 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/21 15:12:03 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

/* sorting algorithims */

void	push_swap(t_stack **a, t_stack **b);

void	sort_three(t_stack **a);

void	create_stack(t_stack **stack, char **values);

/* push commands */

void	push(t_stack **dest, t_stack **src);

void	pa(t_stack **a, t_stack **b);

void	pb(t_stack **b, t_stack **a);

/* rotate commands */

void	rotate(t_stack **stack);

void	ra(t_stack **a);

void	rb(t_stack **b);

void	rr(t_stack **a, t_stack **b);

/* reverse rotate commands */

void	reverse_rotate(t_stack **stack);

void	rra(t_stack **a);

void	rrb(t_stack **b);

void	rrr(t_stack **a, t_stack **b);

/* swap commands */

void	swap(t_stack **head);

void	sa(t_stack **a);

void	sb(t_stack **b);

void	ss(t_stack **a, t_stack **b);

/* move nodes */

void	move_nodes(t_stack **a, t_stack **b);

void	rotate_up(t_stack **a, t_stack **b, t_stack *cheapest);

void	rotate_down(t_stack **a, t_stack **b, t_stack *cheapest);

void	bring_to_top(t_stack **stack, t_stack *node, char name);

/* get utils */

t_stack	*get_cheapest(t_stack *stack);

t_stack	*get_smallest(t_stack *stack);

t_stack	*get_highest(t_stack *a);

size_t	get_biggest(t_stack *stack);

/* set utils */

void	set_nodes(t_stack *a, t_stack *b);

void	set_target(t_stack *a, t_stack *b);

void	set_cheapest(t_stack *b);

void	set_cost(t_stack *a, t_stack *b);

void	set_index(t_stack *stack);

/* stack utils */

void	add_stack_member(t_stack **stack, int value);

t_stack	*stack_last(t_stack *stack);

int		stack_sorted(t_stack *a);

int		stack_size(t_stack *stack);

/* free utils */

void	free_stack(t_stack **stack);

void	free_values(char **values);

void	free_all(t_stack **stack, char **values, int flag);

/* handle utils */

char	**parse_args(int ac, char **av);

char	*handle_str(char *s1, char *s2);

int		handle_args(int ac, char **av);

/* error utils */

int		check_duplicates(t_stack *stack, int nbr);

int		check_syntax(char *str);

int		check_int(char *str);

/* libft utils */

char	**ft_split(char const *s, char c);

int		ft_wordcount(char const *s, char sep);

char	**ft_allocatewords(char **arr, char const *s, char sep);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_freeall(char **arr, int i);

void	*ft_calloc(size_t count, size_t size);

void	ft_bzero(void *s, size_t n);

long	ft_atol(const char *str);

int		ft_overflow_check(int sign);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* string utils */

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strcat(char *s1, const char *s2);

size_t	ft_strlen(const char *s);

void	ft_putstr_fd(char *s, int fd);

/* is utils */

int		ft_isdigit(int c);

int		ft_isspace(int c);

int		ft_issign(int c);

#endif
