/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two_stacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:17:11 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:15:15 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	shift_up(stack_a);
	shift_up(stack_b);
}

void	shift_down_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	shift_down(stack_a);
	shift_down(stack_b);
}

void	swap_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
