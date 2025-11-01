/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_impl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:06:59 by rukabash          #+#    #+#             */
/*   Updated: 2025/11/01 14:07:01 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	initial_partition(t_list **stack1, t_list **stack2,
	t_sort_params *push, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if ((*stack1)->index <= push->mid)
			pb(stack1, stack2);
		else
		{
			if (ft_lstsize(*stack2) > 1 && (*stack2)->index < (push->mid / 2))
				rr(stack1, stack2);
			else
				ra(stack1);
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	process_next_element(t_list **stack1, t_list **stack2,
	t_sort_params *push)
{
	if (ft_lstsize(*stack2) > 0 && ((*stack2)->index == push->next))
		pa(stack1, stack2);
	else if ((*stack1)->index == push->next)
	{
		(*stack1)->flag = -1;
		ra(stack1);
		push->next++;
	}
	else if ((ft_lstsize(*stack2)) > 2
		&& ft_lstlast(*stack2)->index == push->next)
		rrb(stack2);
	else if ((*stack1)->next->index == push->next)
		sa(stack1);
	else if ((ft_lstsize(*stack1)) > 1 && ((*stack1)->next->index == push->next)
		&& ((*stack2)->next->index == push->next + 1))
		ss(stack1, stack2);
	else
		return ;
	process_next_element(stack1, stack2, push);
}

void	sort_partition_a(t_list **stack1, t_list **stack2, t_sort_params *push)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = ft_lstsize(*stack2);
	while (ft_lstsize(*stack2) && ++i < count_b)
	{
		if ((*stack2)->index == push->next)
			process_next_element(stack1, stack2, push);
		else if ((*stack2)->index >= push->mid)
		{
			(*stack2)->flag = push->flag;
			pa(stack1, stack2);
		}
		else if ((*stack2)->index < push->mid)
			rb(stack2);
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	sort_partition_b(t_list **stack1, t_list **stack2, t_sort_params *push)
{
	int	now_flag;

	now_flag = (*stack1)->flag;
	if ((*stack1)->flag != 0)
	{
		while ((*stack1)->flag == now_flag)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			process_next_element(stack1, stack2, push);
		}
	}
	else if ((*stack1)->flag == 0)
	{
		while ((*stack1)->flag != -1)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			process_next_element(stack1, stack2, push);
		}
	}
	if (ft_lstsize(*stack2))
		push->max = (get_max_node(stack2))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

void	start_large_sort(t_list **stack1, t_list **stack2, int count)
{
	t_sort_params	push;

	push.next = get_min_node(stack1)->index;
	push.max = get_max_node(stack1)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	initial_partition(stack1, stack2, &push, count);
	while (!(is_final_sorted(stack1, count)))
	{
		if (ft_lstsize(*stack2) == 0)
			sort_partition_b(stack1, stack2, &push);
		else
			sort_partition_a(stack1, stack2, &push);
	}
}
