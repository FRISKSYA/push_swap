/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:27 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/15 16:31:23 by kfukuhar         ###   ########.fr       */
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

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q push_swap");
}

// TODO: fix before finish.
int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*tail_ptr;

	if (argc == 1)
		return (0);
	if (validate_args(argc, argv) == ERROR)
		return (print_error());
	ft_printf("Validate: SUCCESS\n");
	stack_a = NULL;
	if (fill_stacks(&stack_a, --argc, ++argv) == ERROR)
		return (print_error());
	tail_ptr = NULL;
	tail_ptr = ft_lstlast(stack_a);
	sort_stacks(&stack_a);
	ft_printf("Print Nodes:\n");
	while (stack_a->next)
	{
		ft_printf("%d index'nbr is %d.\n", stack_a->index, stack_a->nbr);
		stack_a = stack_a->next;
	}
	ft_printf("End node: %d index'nbr is %d.\n", stack_a->index, stack_a->nbr);
	stack_a = ft_lsthead(tail_ptr);
	ft_printf("free list a is %d : 0 is SUCCESS\n", ft_lstclear(&stack_a));
	return (0);
}
