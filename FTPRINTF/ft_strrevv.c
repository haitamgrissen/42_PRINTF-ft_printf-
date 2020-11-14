/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:14:03 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 12:04:56 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrevv(char *str)
{
	int		length;
	int		j;
	int		i;
	char	temp;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	i = 0;
	j = length - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

void	ft_putstr_flaged(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '0' && flags->minwidth == 0 && flags->point)
			break ;
		ft_putchar(str[i]);
		i++;
	}
}
