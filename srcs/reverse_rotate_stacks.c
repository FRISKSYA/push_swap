/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:57:30 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 21:59:32 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rev_rotate_stacks(t_stack **lst)
{
	t_stack	*node_0;
	t_stack	*node_tail;
	t_stack	*node_tail_prev;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return (ERROR);
	node_0 = *lst;
	node_tail = ft_lstlast(*lst);
	node_tail_prev = node_tail->prev;
	node_0->prev = node_tail;
	if (node_tail != node_0)
	{
		node_tail->next = node_0;
		node_tail->prev = NULL;
	}
	if (node_tail_prev != node_0 || node_tail_prev != NULL)
		node_tail_prev->next = NULL;
	*lst = node_tail;
	return (SUCCESS);
}

int	rra(t_stack **lst)
{
	if (rev_rotate_stacks(lst) == SUCCESS)
	{
		ft_printf("rra\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

int	rrb(t_stack **lst)
{
	if (rev_rotate_stacks(lst) == SUCCESS)
	{
		ft_printf("rrb\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

int	rrr(t_stack **a, t_stack **b)
{
	if (rev_rotate_stacks(a) == SUCCESS && rev_rotate_stacks(b) == SUCCESS)
	{
		ft_printf("rrr\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

//// test:
//#include <stdio.h>
//#include <stdlib.h>
//
//t_stack *create_node(int nbr, size_t index)
//{
//    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
//    if (!node)
//        return NULL;
//    node->nbr = nbr;
//    node->index = index;
//    node->next = NULL;
//    node->prev = NULL;
//    return node;
//}
//
//void print_stack(t_stack *lst)
//{
//    while (lst)
//    {
//        printf("Node: index = %zu, nbr = %ld\n", lst->index, lst->nbr);
//        lst = lst->next;
//    }
//}
//
//void free_stack(t_stack **lst)
//{
//    t_stack *tmp;
//
//    while (*lst)
//    {
//        tmp = (*lst)->next;
//        free(*lst);
//        *lst = tmp;
//    }
//}
//int main()
//{
//    t_stack *stack_a = NULL;
//    t_stack *new_node;
//
//    // Test case 1: Normal case with multiple nodes
//    new_node = create_node(1, 0);
//    stack_a = new_node;
//    new_node->next = create_node(2, 1);
//    new_node->next->prev = new_node;
//    new_node = new_node->next;
//    new_node->next = create_node(3, 2);
//    new_node->next->prev = new_node;
//
//    printf("Original stack:\n");
//    print_stack(stack_a);
//
//    // Perform reverse rotate
//    rev_rotate_stacks(&stack_a);
//
//    printf("\nStack after reverse rotate:\n");
//    stack_a = ft_lsthead(stack_a);
//    print_stack(stack_a);
//
//    // Free the stack
//    free_stack(&stack_a);
//
//    // Test case 2: Single node
//    new_node = create_node(1, 0);
//    stack_a = new_node;
//
//    printf("\nSingle node stack before reverse rotate:\n");
//    print_stack(stack_a);
//
//    // Perform reverse rotate
//    rev_rotate_stacks(&stack_a);
//
//    printf("\nSingle node stack after reverse rotate:\n");
//    print_stack(stack_a);
//
//    // Free the stack
//    free_stack(&stack_a);
//
//    // Test case 3: Empty stack
//    stack_a = NULL;
//
//    printf("\nEmpty stack before reverse rotate:\n");
//    print_stack(stack_a);
//
//    // Perform reverse rotate
//    rev_rotate_stacks(&stack_a);
//
//    printf("\nEmpty stack after reverse rotate:\n");
//    print_stack(stack_a);
//
//    // Test case 4: Larger stack
//    for (int i = 0; i < 10; i++) {
//        new_node = create_node(i, i);
//        new_node->next = stack_a;
//        if (stack_a != NULL)
//            stack_a->prev = new_node;
//        stack_a = new_node;
//    }
//
//    printf("\nLarger stack before reverse rotate:\n");
//    print_stack(stack_a);
//
//    // Perform reverse rotate
//    rev_rotate_stacks(&stack_a);
//
//    printf("\nLarger stack after reverse rotate:\n");
//    stack_a = ft_lsthead(stack_a);
//    print_stack(stack_a);
//
//    // Free the stack
//    free_stack(&stack_a);
//
//    return 0;
//}
