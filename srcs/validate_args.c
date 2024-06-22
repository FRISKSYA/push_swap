/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:59:48 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/22 22:01:05 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_intstr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (true);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static int	is_int(char *str)
{
	long int	li;

	if (is_intstr(str) == false)
		return (false);
	li = 0;
	li = ft_atoi(str);
	if (li > INT_MAX || li < INT_MIN)
		return (false);
	return (true);
}

static int	has_dup(char **str_arr)
{
	size_t	i;
	size_t	j;
	char	*word;

	i = 0;
	word = NULL;
	while (str_arr[i])
	{
		word = str_arr[i];
		j = i + 1;
		while (str_arr[j])
		{
			if (ft_strcmp(word, str_arr[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	validate_single_arg(char **str_arr)
{
	size_t	i;

	if (str_arr == NULL)
		return (ERROR);
	i = 0;
	while (str_arr[i])
	{
		if (is_int(str_arr[i]) == false)
		{
			free_str_arr(str_arr);
			return (ERROR);
		}
		i++;
	}
	if (has_dup(str_arr) == true)
	{
		free_str_arr(str_arr);
		return (ERROR);
	}
	return (free_str_arr(str_arr));
}

// Rules:
// 1. type == int
// 	a. isdigit
// 	b. isinINTranges
// 2. dont dup
// FIXME: bad structure
int	validate_args(int argc, char **argv)
{
	size_t	i;
	char	**str_arr;

	if (argc == 2)
	{
		str_arr = NULL;
		str_arr = ft_split(argv[1], ' ');
		return (validate_single_arg(str_arr));
	}
	i = 1;
	while (argv[i])
	{
		if (is_int(argv[i]) == false)
			return (ERROR);
		i++;
	}
	if (has_dup(++argv) == true)
		return (ERROR);
	else
		return (SUCCESS);
}
