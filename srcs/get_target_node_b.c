/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_node_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:10:09 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 21:59:21 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*find_target_node(t_stack *cur_b, t_stack *s_b, long a_val)
{
	t_stack	*tgt;
	long	closest_smaller_value;

	tgt = NULL;
	closest_smaller_value = LONG_MIN;
	while (cur_b && (cur_b != s_b || !tgt))
	{
		if (cur_b->nbr < a_val && cur_b->nbr > closest_smaller_value)
		{
			closest_smaller_value = cur_b->nbr;
			tgt = cur_b;
		}
		cur_b = cur_b->next;
	}
	return (tgt);
}

static t_stack	*find_max_node(t_stack *cur_b, t_stack *s_b)
{
	t_stack	*tgt;
	long	max_nbr;

	tgt = s_b;
	max_nbr = s_b->nbr;
	cur_b = s_b->next;
	while (cur_b && cur_b != s_b)
	{
		if (cur_b->nbr > max_nbr)
		{
			max_nbr = cur_b->nbr;
			tgt = cur_b;
		}
		cur_b = cur_b->next;
	}
	return (tgt);
}

t_stack	*get_target_node_b(t_stack **s_a, t_stack **s_b)
{
	int			a_nbr;
	t_stack		*current_b;
	t_stack		*tgt;

	if (!s_a || !s_b || !*s_a)
		return (NULL);
	a_nbr = (*s_a)->nbr;
	current_b = *s_b;
	tgt = NULL;
	tgt = find_target_node(current_b, *s_b, a_nbr);
	if (!tgt)
		tgt = find_max_node(current_b, *s_b);
	return (tgt);
}
//
//#include <stdio.h>
//
//t_stack *create_node(int nbr) {
//    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
//    if (node) {
//        node->nbr = nbr;
//        node->prev = node->next = NULL;
//    }
//    return node;
//}
//
//void connect_nodes(t_stack *prev, t_stack *next) {
//    prev->next = next;
//    next->prev = prev;
//}
//
//void print_list(t_stack *head) {
//    t_stack *current = head;
//    while (current) {
//        printf("%ld ", current->nbr);
//        current = current->next;
//    }
//    printf("\n");
//}
//
//int main() {
//    t_stack *stack_a = create_node(8);
//    t_stack *node_a1 = create_node(1);
//    t_stack *node_a2 = create_node(4);
//    t_stack *node_a3 = create_node(2);
//
//    connect_nodes(stack_a, node_a1);
//    connect_nodes(node_a1, node_a2);
//    connect_nodes(node_a2, node_a3);
//
//    t_stack *stack_b = create_node(5);
//    t_stack *node_b1 = create_node(9);
//    t_stack *node_b2 = create_node(7);
//    t_stack *node_b3 = create_node(6);
//
//    connect_nodes(stack_b, node_b1);
//    connect_nodes(node_b1, node_b2);
//    connect_nodes(node_b2, node_b3);
//
//    printf("stack_a: ");
//    print_list(stack_a);
//    printf("stack_b: ");
//    print_list(stack_b);
//
//    t_stack *target_node = find_target_node(stack_b, stack_b, stack_a->nbr);
//    if (target_node) {
//        printf("Target node found with value: %ld\n", target_node->nbr);
//    } else {
//        printf("Target node not found\n");
//    }
//
//    t_stack *max_node = find_max_node(stack_b, stack_b);
//    if (max_node) {
//        printf("Max node found with value: %ld\n", max_node->nbr);
//    } else {
//        printf("Max node not found\n");
//    }
//
//    t_stack *target_node_b = get_target_node_b(&stack_a, &stack_b);
//    if (target_node_b) {
//        printf(
//        "Target node for stack_b found with value: %ld\n",
//        target_node_b->nbr
//        );
//    } else {
//        printf("Target node for stack_b not found\n");
//    }
//
//    free(stack_a);
//    free(node_a1);
//    free(node_a2);
//    free(node_a3);
//    free(stack_b);
//    free(node_b1);
//    free(node_b2);
//    free(node_b3);
//
//    return 0;
//}
