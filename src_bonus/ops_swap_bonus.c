/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:55:15 by rukabash          #+#    #+#             */
/*   Updated: 2025/11/01 13:55:16 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	internal_swap_bonus(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list **stack1)
{
	internal_swap_bonus(stack1);
}

void	sb(t_list **stack2)
{
	internal_swap_bonus(stack2);
}

void	ss(t_list **stack1, t_list **stack2)
{
	internal_swap_bonus(stack1);
	internal_swap_bonus(stack2);
}
