/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:58:06 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/15 15:13:19 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rotate_stacks(t_stack **lst)
{
	t_stack	*node_0;
	t_stack	*node_1;
	t_stack	*node_tail;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return (ERROR);
	node_0 = *lst;
	node_1 = node_0->next;
	node_tail = ft_lstlast(*lst);
	node_0->next = NULL;
	node_0->prev = node_tail;
	node_1->prev = NULL;
	if (node_tail != NULL)
		node_tail->next = node_0;
	*lst = node_1;
	return (SUCCESS);
}

int	ra(t_stack **lst)
{
	if (rotate_stacks(lst) == SUCCESS)
	{
		ft_printf("ra\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

int	rb(t_stack **lst)
{
	if (rotate_stacks(lst) == SUCCESS)
	{
		ft_printf("rb\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

int	rr(t_stack **a, t_stack **b)
{
	if (rotate_stacks(a) == SUCCESS && rotate_stacks(b) == SUCCESS)
	{
		ft_printf("rr\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

// tests:
//#include <stdio.h>
//#include <stdlib.h>
//
//// Function to print the stack
//void print_stack(t_stack *lst) {
//    printf("Printing stack:\n");
//    while (lst != NULL) {
//        printf("Node: nbr = %ld, index = %zu\n", lst->nbr, lst->index);
//        lst = lst->next;
//    }
//}
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}
//int main() {
//    // Create some nodes for testing
//    t_stack *node1 = (t_stack *)malloc(sizeof(t_stack));
//    t_stack *node2 = (t_stack *)malloc(sizeof(t_stack));
//    //t_stack *node3 = (t_stack *)malloc(sizeof(t_stack));
//
//    // Initialize nodes
//    node1->nbr = 10;
//    node1->index = 1;
//    node1->prev = NULL;
//    node1->next = node2;
//
//    node2->nbr = 20;
//    node2->index = 2;
//    node2->prev = node1;
//    node2->next = NULL;
//
////    node3->nbr = 30;
////    node3->index = 3;
////    node3->prev = node2;
////    node3->next = NULL;
//
//    t_stack *stack = node1; // Point to the head of the stack
//
//    // Print initial stack
//    printf("Before rotation:\n");
//    print_stack(stack);
//
//    // Rotate the stack
//    rotate_stacks(&stack);
//
//    // Print stack after rotation
//    printf("\nAfter rotation:\n");
//    print_stack(stack);
//
//    // Free allocated memory
//    free(node1);
//    free(node2);
////	free(node3);
//
//    return 0;
//}
