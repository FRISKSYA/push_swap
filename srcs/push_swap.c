/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:27 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/21 18:58:25 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TODO: 1. validate args.
// TODO: 2. fill stacks from args.
// TODO: 3. sort and print the action.

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (ERROR);
}

//__attribute__((destructor)) static void	destructor(void)
//{
//	system("leaks -q push_swap");
//}

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;

	if (argc == 1)
		return (SUCCESS);
	if (validate_args(argc, argv) == ERROR)
		return (print_error());
	stack_a = NULL;
	if (fill_stacks(&stack_a, --argc, ++argv) == ERROR)
		return (print_error());
	if (issort_asc(stack_a) == true)
	{
		ft_lstclear(&stack_a);
		return (SUCCESS);
	}
	sort_stacks(&stack_a);
	stack_a = ft_lsthead(stack_a);
	ft_lstclear(&stack_a);
	return (SUCCESS);
}
