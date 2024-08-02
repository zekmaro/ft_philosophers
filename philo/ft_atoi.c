/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejarama <andrejarama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:58:11 by anarama           #+#    #+#             */
/*   Updated: 2024/08/01 18:52:05 by andrejarama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int			num;
	const char	*temp_str;

	if (str == NULL)
		return (0);
	num = 0;
	temp_str = skip_spaces(str);
	if (*temp_str == '-' || *temp_str == '+')
		temp_str++;
	while ((*temp_str - '0') >= 0 && (*temp_str - '0') <= 9)
	{
		num *= 10;
		num += *temp_str - '0';
		temp_str++;
	}
	if (*skip_spaces(str) == '-')
		num *= -1;
	return (num);
}
