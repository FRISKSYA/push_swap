/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:46:41 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 22:00:24 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	swap_nodes(t_stack **lst)
{
	t_stack	*node_0;
	t_stack	*node_1;
	t_stack	*node_2;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return (ERROR);
	node_0 = *lst;
	node_1 = node_0->next;
	node_2 = node_1->next;
	node_1->prev = NULL;
	node_1->next = node_0;
	node_0->prev = node_1;
	node_0->next = node_2;
	if (node_2 != NULL)
		node_2->prev = node_0;
	*lst = node_1;
	return (SUCCESS);
}

int	sa(t_stack **lst)
{
	if (swap_nodes(lst) == SUCCESS)
	{
		ft_printf("sa\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

int	sb(t_stack **lst)
{
	if (swap_nodes(lst) == SUCCESS)
	{
		ft_printf("sb\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

int	ss(t_stack **a, t_stack **b)
{
	if (swap_nodes(a) == SUCCESS && swap_nodes(b) == SUCCESS)
	{
		ft_printf("ss\n");
		return (SUCCESS);
	}
	else
		return (ERROR);
}

// test funcs:
//#include <stdio.h>
//#include <stdlib.h>
//
//t_stack *create_node(int nbr, size_t index) {
//    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
//    if (new_node == NULL) {
//        perror("Failed to allocate memory");
//        exit(EXIT_FAILURE);
//    }
//    new_node->nbr = nbr;
//    new_node->index = index;
//    new_node->next = NULL;
//    new_node->prev = NULL;
//    return new_node;
//}
//
//void print_list(t_stack *head) {
//    t_stack *current = head;
//    while (current != NULL) {
//        printf("Node [nbr: %ld, index: %zu]\n", current->nbr, current->index);
//        current = current->next;
//    }
//}
//
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}
//
//int main() {
//    t_stack *node1 = create_node(1, 0);
//    t_stack *node2 = create_node(2, 1);
////    t_stack *node3 = create_node(3, 2);
////    t_stack *node4 = create_node(4, 3);
//
//    node1->next = node2;
//    node2->prev = node1;
////    node2->next = node3;
////    node3->prev = node2;
////    node3->next = node4;
////    node4->prev = node3;
//
//    t_stack *list = node1;
//
//    printf("Before swapping:\n");
//    print_list(list);
//
//    if (swap_nodes(&list) == SUCCESS) {
//        printf("\nAfter swapping:\n");
//        print_list(list);
//    } else {
//        printf("Swap failed.\n");
//    }
//
//    free(node1);
//    free(node2);
////    free(node3);
////    free(node4);
//
//    return 0;
//}
