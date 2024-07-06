/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejarama <andrejarama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:31:40 by anarama           #+#    #+#             */
/*   Updated: 2024/07/06 23:45:14 by andrejarama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*temp_str;

	temp_str = (char *)str;
	while (n--)
		*temp_str++ = c;
	return (str);
}
