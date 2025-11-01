/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:55:06 by rukabash          #+#    #+#             */
/*   Updated: 2025/11/01 13:55:08 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	internal_rotate_bonus(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list **stack1)
{
	internal_rotate_bonus(stack1);
}

void	rb(t_list **stack2)
{
	internal_rotate_bonus(stack2);
}

void	rr(t_list **stack1, t_list **stack2)
{
	internal_rotate_bonus(stack1);
	internal_rotate_bonus(stack2);
}
