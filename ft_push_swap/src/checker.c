/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:16:11 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/26 02:27:54 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_instruction(t_stack *stack_a, t_stack *stack_b,
			char *instruction)
{
	if (ft_strncmp(instruction, "pb", ft_strlen(instruction)) == 0)
		push_from_to(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pa", ft_strlen(instruction)) == 0)
		push_from_to(stack_b, stack_a);
	else if (ft_strncmp(instruction, "sa", ft_strlen(instruction)) == 0)
		swap(stack_a);
	else if (ft_strncmp(instruction, "sb", ft_strlen(instruction)) == 0)
		swap(stack_b);
	else if (ft_strncmp(instruction, "ss", ft_strlen(instruction)) == 0)
		swap_both_stacks(stack_a, stack_b);
	else if (ft_strncmp(instruction, "ra", ft_strlen(instruction)) == 0)
		shift_up(stack_a);
	else if (ft_strncmp(instruction, "rb", ft_strlen(instruction)) == 0)
		shift_up(stack_b);
	else if (ft_strncmp(instruction, "rr", ft_strlen(instruction)) == 0)
		shift_up_both_stacks(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rra", ft_strlen(instruction)) == 0)
		shift_down(stack_a);
	else if (ft_strncmp(instruction, "rrb", ft_strlen(instruction)) == 0)
		shift_down(stack_b);
	else if (ft_strncmp(instruction, "rrr", ft_strlen(instruction)) == 0)
		shift_down_both_stacks(stack_a, stack_b);
	else
		exit_with_error();
}

void	checker(char **numbers)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*instruction;

	stack_init(&stack_a, calc_table_len(numbers));
	stack_init(&stack_b, calc_table_len(numbers));
	fill_stack_with_numbers(&stack_a, numbers);
	if (stack_a.size >= 1)
	{
		while (get_next_line(0, &instruction))
		{
			if (instruction[0] == '\0')
				exit_with_error();
			ft_execute_instruction(&stack_a, &stack_b, instruction);
			free(instruction);
			instruction = NULL;
		}
		if ((stack_b.size == 0) && (is_stack_not_sorted(stack_a) == 0))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	free(stack_a.data);
	free(stack_b.data);
}

int	main(int argc, char **argv)
{
	char	**numbers;

	numbers = store_numbers(argv, argc);
	if (check_numbers(numbers))
	{
		checker(numbers);
	}
	free_numbers(numbers);
	return (0);
}
