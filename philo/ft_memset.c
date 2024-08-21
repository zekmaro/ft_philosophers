/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:31:40 by anarama           #+#    #+#             */
/*   Updated: 2024/08/20 17:39:39 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*temp_str;

	temp_str = (char *)str;
	while (n--)
		*temp_str++ = c;
	return (str);
}
