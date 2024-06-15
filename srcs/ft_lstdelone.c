/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:36:33 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/13 14:37:52 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstdelone(t_stack **lst)
{
	if (*lst == NULL)
		return (SUCCESS);
	(*lst)->next = NULL;
	(*lst)->prev = NULL;
	free(*lst);
	*lst = NULL;
	return (SUCCESS);
}
//
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q a.out");
//}
//
//#include <stdio.h>
//int main()
//{
//    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
//    if (node == NULL)
//    {
//        perror("Failed to allocate memory");
//        return 1;
//    }
//
//    node->nbr = 42;
//    node->index = 1;
//    node->next = NULL;
//    node->prev = NULL;
//
//    printf("Before deletion:\n");
//    printf("Node address: %p\n", (void *)node);
//    printf("Node value: %ld\n", node->nbr);
//    printf("Node index: %zu\n", node->index);
//
//    ft_lstdelone(&node);
//
//    printf("After deletion:\n");
//    if (node == NULL)
//    {
//        printf("Node successfully deleted and set to NULL\n");
//    }
//    else
//    {
//        printf("Node address: %p\n", (void *)node);
//        printf("Node value: %ld\n", node->nbr);
//        printf("Node index: %zu\n", node->index);
//    }
//
//    return 0;
//}
