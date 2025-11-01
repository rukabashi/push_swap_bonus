/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:52:37 by rukabash          #+#    #+#             */
/*   Updated: 2025/10/24 16:52:39 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*strtosrc;
	size_t			i;

	strtosrc = (unsigned char *)memoryBlock;
	i = 0;
	while (i < size)
	{
		if (*strtosrc == (unsigned char)searchedChar)
			return (strtosrc);
		strtosrc++;
		i++;
	}
	return (NULL);
}
