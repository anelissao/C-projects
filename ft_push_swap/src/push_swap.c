/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:19:02 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/26 00:44:50 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**numbers;

	numbers = store_numbers(argv, argc);
	if (check_numbers(numbers))
	{
		stack_init(&stack_a, calc_table_len(numbers));
		stack_init(&stack_b, calc_table_len(numbers));
		fill_stack_with_numbers(&stack_a, numbers);
		if (stack_a.size >= 2 && is_stack_not_sorted(stack_a))
			start_stack_sorting(&stack_a, &stack_b);
		free(stack_a.data);
		free(stack_b.data);
	}
	free_numbers(numbers);
	return (0);
}
