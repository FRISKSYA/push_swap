/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:50:44 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/13 12:12:01 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_str_arr(char **str_arr)
{
	size_t	i;

	if (str_arr == NULL)
		return (SUCCESS);
	i = 0;
	while (str_arr[i])
		free(str_arr[i++]);
	free(str_arr);
	return (SUCCESS);
}
