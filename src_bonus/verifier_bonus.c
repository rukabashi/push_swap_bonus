/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:09:58 by rukabash          #+#    #+#             */
/*   Updated: 2025/11/01 14:10:00 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	parse_operation(char *input, t_check_stacks *tab)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(&tab->stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(&tab->stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(&tab->stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(&tab->stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(&tab->stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(&tab->stack_b);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
}

int	validate_input_bonus(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+')
					&& ft_isdigit(nbr[i + 1])) || ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*initialize_stack_bonus(char **ag, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nbr;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (ag[i])
	{
		nbr = ft_atoi(ag[i]);
		if (!(nbr < INT_MAX && nbr > INT_MIN)
			|| validate_input_bonus(res, nbr, ag[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

void	read_instructions(t_check_stacks *tab)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!parse_operation(input, tab))
		{
			ft_putstr_fd("Error\n", 1);
			exit(-1);
		}
		input = get_next_line(0);
	}
}

int	main(int ac, char **ag)
{
	t_check_stacks	*tab;

	if (ac == 2)
		ag = ft_split(ag[1], ' ');
	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_check_stacks));
	if (!tab)
		return (-1);
	tab->stack_b = NULL;
	tab->stack_a = initialize_stack_bonus(ag, ac);
	if (tab->stack_a == NULL)
		return (-1);
	read_instructions(tab);
	if (is_stack_sorted(tab->stack_a) && !tab->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
