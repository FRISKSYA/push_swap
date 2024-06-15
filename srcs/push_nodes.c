/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:09:18 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/15 16:16:58 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	push_nodes(t_stack **dst, t_stack **src)
{
	t_stack	*node_s0;
	t_stack	*node_s1;
	t_stack	*node_d0;

	if (src == NULL || *src == NULL)
		return (ERROR);
	node_s0 = *src;
	node_s1 = node_s0->next;
	if (dst == NULL)
		node_d0 = NULL;
	else
		node_d0 = *dst;
	node_s0->next = node_d0;
	ft_printf("check seg\n");
	if (node_s1 != NULL)
		node_s1->prev = NULL;
	if (node_d0 != NULL)
		node_d0->prev = node_s0;
	ft_printf("done seg\n");
	*src = node_s1;
	dst = &node_s0;
	return (SUCCESS);
}

int	pa(t_stack **a, t_stack **b)
{
	if (push_nodes(a, b) == SUCCESS)
	{
		ft_printf("pa\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push_nodes(b, a) == SUCCESS)
	{
		ft_printf("pb\n");
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
//    // Create some nodes for src stack
//    t_stack *src_node1 = (t_stack *)malloc(sizeof(t_stack));
//    t_stack *src_node2 = (t_stack *)malloc(sizeof(t_stack));
//    t_stack *src_node3 = (t_stack *)malloc(sizeof(t_stack));
//    t_stack *dst_node1 = (t_stack *)malloc(sizeof(t_stack));
//
//    // Initialize src nodes
//    src_node1->nbr = 10;
//    src_node1->index = 1;
//    src_node1->prev = NULL;
//    src_node1->next = src_node2;
//
//    src_node2->nbr = 20;
//    src_node2->index = 2;
//    src_node2->prev = src_node1;
//    src_node2->next = src_node3;
//
//    src_node3->nbr = 30;
//    src_node3->index = 3;
//    src_node3->prev = src_node2;
//    src_node3->next = NULL;
//
//    t_stack *src_stack = src_node1; // Point to the head of the src stack
//
//    // Create dst stack (initially empty)
//    dst_node1->nbr = -10;
//    dst_node1->index = 1;
//    dst_node1->prev = NULL;
//    dst_node1->next = NULL;
//    t_stack *dst_stack = dst_node1;
//
//    // Print initial stacks
//    printf("Before pushing nodes:\n");
//    printf("Source stack:\n");
//    print_stack(src_stack);
//    printf("Destination stack:\n");
//    print_stack(dst_stack);
//
//    // Push nodes from src to dst
//    push_nodes(&dst_stack, &src_stack);
//
//    // Print stacks after pushing nodes
//    printf("\nAfter pushing nodes:\n");
//    printf("Source stack:\n");
//    print_stack(src_stack); // Print src_stack to show it hasn't been modified
//    printf("Destination stack:\n");
//    print_stack(dst_stack);
//
//    // Free allocated memory
//    free(src_node1);
//    free(src_node2);
//    free(src_node3);
//    free(dst_node1);
//
//    return 0;
//}
