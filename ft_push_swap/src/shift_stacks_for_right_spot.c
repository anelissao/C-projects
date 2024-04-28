/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stacks_for_right_spot.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:16:26 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:25:55 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up_stacks(t_stack *stack_a, t_stack *stack_b,
			int move_a, int move_b)
{
	while (move_a > 0 && move_b > 0)
	{
		ft_putstr_fd("rr\n", 1);
		shift_up_both_stacks(stack_a, stack_b);
		move_a--;
		move_b--;
	}
	while (move_a > 0)
	{
		ft_putstr_fd("ra\n", 1);
		shift_up(stack_a);
		move_a--;
	}
	while (move_b > 0)
	{
		ft_putstr_fd("rb\n", 1);
		shift_up(stack_b);
		move_b--;
	}
}

void	shift_down_stacks(t_stack *stack_a, t_stack *stack_b,
			int move_a, int move_b)
{
	while (move_a < 0 && move_b < 0)
	{
		ft_putstr_fd("rrr\n", 1);
		shift_down_both_stacks(stack_a, stack_b);
		move_a = move_a + 1;
		move_b = move_b + 1;
	}
	while (move_a < 0)
	{
		ft_putstr_fd("rra\n", 1);
		shift_down(stack_a);
		move_a = move_a + 1;
	}
	while (move_b < 0)
	{
		ft_putstr_fd("rrb\n", 1);
		shift_down(stack_b);
		move_b = move_b + 1;
	}	
}

void	shift_stacks(t_stack *stack_a, t_stack *stack_b,
			int move_a, int move_b)
{
	while (move_a < 0)
	{
		ft_putstr_fd("rra\n", 1);
		shift_down(stack_a);
		move_a = move_a + 1;
	}
	while (move_b < 0)
	{
		ft_putstr_fd("rrb\n", 1);
		shift_down(stack_b);
		move_b = move_b + 1;
	}
	while (move_a > 0)
	{
		ft_putstr_fd("ra\n", 1);
		shift_up(stack_a);
		move_a--;
	}
	while (move_b > 0)
	{
		ft_putstr_fd("rb\n", 1);
		shift_up(stack_b);
		move_b--;
	}
}

void	shift_stacks_for_right_spot(t_stack *stack_a, t_stack *stack_b,
			int move_a, int move_b)
{
	if ((move_a * move_b) > 0)
	{
		if (move_a > 0)
			shift_up_stacks(stack_a, stack_b, move_a, move_b);
		else if (move_a < 0)
			shift_down_stacks(stack_a, stack_b, move_a, move_b);
	}
	else
		shift_stacks(stack_a, stack_b, move_a, move_b);
}

void	shift_stack_a_to_be_sorted(t_stack *stack_a)
{
	int	min_index;

	min_index = locate_min_num(stack_a);
	if (min_index == 0)
		return ;
	if (min_index > (stack_a->size / 2))
	{
		while (min_index < stack_a->size)
		{
			ft_putstr_fd("rra\n", 1);
			shift_down(stack_a);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ft_putstr_fd("ra\n", 1);
			shift_up(stack_a);
			min_index--;
		}
	}
}
