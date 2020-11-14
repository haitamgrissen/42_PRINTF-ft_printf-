/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:03:18 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 12:04:56 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_flagedr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_mystrlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	normal_str(t_flags *flags, char *str)
{
	while (flags->minwidth > 0 && (flags->minwidth--))
		ft_putchar(' ');
	if (flags->check && !flags->precision && flags->point)
		return ;
	if (flags->precision)
	{
		while (flags->precision > 0 && (flags->precision--))
		{
			ft_putchar(*str);
			str++;
		}
		return ;
	}
	if (!(flags->point && !flags->precision && *str == '0'))
		ft_putstr_flagedr(str);
}

void	minus_str(t_flags *flags, char *str)
{
	if (flags->precision)
	{
		while (flags->precision > 0 && (flags->precision--))
		{
			ft_putchar(*str);
			str++;
		}
	}
	else if (!(flags->point && !flags->precision))
		ft_putstr_flagedr(str);
	while (flags->minwidth > 0 && (flags->minwidth--))
		ft_putchar(' ');
}

void	treat_string(t_flags *flags, char *str)
{
	int len;

	if (!str)
		str = "(null)";
	flags->check = flags->minwidth;
	len = ft_mystrlen(str);
	if (flags->point && !flags->precision)
		flags->check = 1;
	if (flags->precision)
		(flags->precision > len) ? flags->precision = len : 0;
	if (flags->precision)
		((flags->minwidth -= flags->precision) < 0) ? flags->minwidth = 0 : 0;
	if (flags->minwidth && !flags->precision
	&& !flags->point && (flags->minwidth -= len))
		(flags->minwidth < 0) ? flags->minwidth = 0 : 0;
	if (flags->minus)
		minus_str(flags, str);
	else if (!flags->minus)
		normal_str(flags, str);
}
