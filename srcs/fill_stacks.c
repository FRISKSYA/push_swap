/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:03:31 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/14 13:57:49 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	fill_stack_by_split(struct s_stack **stack_a, char **str_arr)
{
	size_t			i;
	char			**split_words;
	struct s_stack	*new_node;

	i = 0;
	new_node = NULL;
	split_words = ft_split(str_arr[0], ' ');
	if (split_words == NULL)
		return (ERROR);
	while (split_words[i])
	{
		ft_printf("%s\n", split_words[i]);
		new_node = ft_lstnew(ft_atoi(split_words[i]));
		if (new_node == NULL)
		{
			free_str_arr(split_words);
			return (ERROR);
		}
		ft_lstadd_back(stack_a, new_node);
		free(split_words[i]);
		i++;
	}
	free(split_words);
	return (SUCCESS);
}

static int	fill_stack(struct s_stack **stack_a, char **str_arr)
{
	size_t			i;
	struct s_stack	*new_node;

	i = 0;
	new_node = NULL;
	while (str_arr[i])
	{
		ft_printf("%s\n", str_arr[i]);
		new_node = ft_lstnew(ft_atoi(str_arr[i]));
		if (new_node == NULL)
			return (ERROR);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (SUCCESS);
}

int	fill_stacks(struct s_stack **stack_a, int count_words, char **str_arr)
{
	size_t			i;
	struct s_stack	*new_node;

	i = 0;
	new_node = NULL;
	if (count_words == 1)
		return (fill_stack_by_split(stack_a, str_arr));
	else
		return (fill_stack(stack_a, str_arr));
}
