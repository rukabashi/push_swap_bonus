/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukabash <rukabash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:53:30 by rukabash          #+#    #+#             */
/*   Updated: 2025/10/24 16:53:31 by rukabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar )
{
	while (*string)
	{
		if (*string == (char) searchedChar)
			return ((char *) string);
		++string;
	}
	if ((char) searchedChar == '\0')
		return ((char *) string);
	else
		return (NULL);
}
