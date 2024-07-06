/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:51 by anarama           #+#    #+#             */
/*   Updated: 2024/05/23 21:24:08 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr_prf(char *str, char c)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
