/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <aelissao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:06:51 by aelissao          #+#    #+#             */
/*   Updated: 2023/02/25 21:07:08 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *given_stack, int alloc_size)
{
	given_stack->data = malloc(sizeof(int) * alloc_size);
	given_stack->size = 0;
}
