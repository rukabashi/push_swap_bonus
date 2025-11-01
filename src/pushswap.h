/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:53:20 by rukabash          #+#    #+#             */
/*   Updated: 2025/11/01 14:03:13 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_sort_params
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_sort_params;

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}		t_stacks;

void	manage_sort(t_stacks	*tab);
int		is_sorted(t_list **stack1);
int		is_final_sorted(t_list **stack1, int count);
t_list	*get_min_node(t_list **stack);
t_list	*get_max_node(t_list **stack);
int		is_reverse_sorted(t_stacks	*tab);

void	pa(t_list **stack1, t_list **stack2);
void	pb(t_list **stack1, t_list **stack2);
void	ra(t_list **stack1);
void	rb(t_list **stack2);
void	rr(t_list **stack1, t_list **stack2);
void	sa(t_list **stack1);
void	sb(t_list **stack2);
void	ss(t_list **stack1, t_list **stack2);
void	rrb(t_list **stack2);
void	rra(t_list **stack1);

void	assign_indices(t_list *lst);

void	start_large_sort(t_list **stack1, t_list **stack2, int count);
#endif
