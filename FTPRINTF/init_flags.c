/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:11:41 by hgrissen          #+#    #+#             */
/*   Updated: 2020/10/17 23:25:58 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_flags *flags)
{
	flags->minus = 0;
	flags->minwidth = 0;
	flags->point = 0;
	flags->precision = 0;
	flags->zero = 0;
	flags->check = 0;
}

void	check_it(const char **str, t_flags *flags, va_list ap)
{
	while ((*(*str) == '-') && (flags->minus = 1))
		(*str)++;
	while ((*(*str) == '0') && (flags->zero = 1))
		((*str))++;
	if ((*(*str) == '*') && (*str)++)
	{
		flags->minwidth = va_arg(ap, int);
		(flags->minwidth < 0) ? ((flags->minus = 1)
				&& (flags->minwidth *= -1)) : 0;
	}
	if ((ft_isdigit(*(*str))))
	{
		flags->minwidth = ft_atoi((*str));
		while (ft_isdigit(*(*str)))
			((*str))++;
	}
	if (*(*str) == '.' && (*str)++)
		flags->point = 1;
}

int		ft_strlennn(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '0' && flags->minwidth == 0 && flags->point)
			break ;
		else if (str[0] == '0')
			return (i);
		i++;
	}
	return (i);
}
