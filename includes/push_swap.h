/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:07:14 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/21 18:52:50 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// libs
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>

typedef enum s_error
{
	SUCCESS = 0,
	ERROR = -1,
}					t_error;

typedef struct s_stack
{
	long int		nbr;
	size_t			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// push and swap
int					sa(t_stack **lst);
int					sb(t_stack **lst);
int					ss(t_stack **a, t_stack **b);
int					pa(t_stack **a, t_stack **b);
int					pb(t_stack **a, t_stack **b);
int					ra(t_stack **lst);
int					rb(t_stack **lst);
int					rr(t_stack **a, t_stack **b);
int					rra(t_stack **lst);
int					rrb(t_stack **lst);
int					rrr(t_stack **a, t_stack **b);

// push_swap utils
int					validate_args(int argc, char **argv);
int					fill_stacks(t_stack **stack_a, int count_words,
						char **str_arr);
int					free_str_arr(char **str_arr);
int					sort_stacks(t_stack **stack_a);
int					move_node_min_ops(t_stack **stack_a, t_stack **stack_b);
int					prepare_stacks(t_stack **stack_a, t_stack **stack_b);
void				push_at_correct_position(t_stack **stack_a,
						t_stack **stack_b);
t_stack				*get_target_node_a(t_stack **s_a, t_stack **s_b);
t_stack				*get_target_node_b(t_stack **s_a, t_stack **s_b);
long int			get_cost_to_head(t_stack *lst_node);
bool				issort_asc(t_stack *lst);

// make_lst
t_stack				*ft_lstnew(long int i);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lsthead(t_stack *lst);
int					ft_lstadd_back(t_stack **lst, t_stack *new_node);
int					ft_lstdelone(t_stack **lst);
int					ft_lstclear(t_stack **lst);
size_t				ft_lstsize(t_stack *lst);

#endif
