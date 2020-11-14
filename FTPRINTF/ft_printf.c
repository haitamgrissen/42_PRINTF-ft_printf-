/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 10:55:25 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 18:12:28 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			ft_putchar(char c)
{
	g_ret += write(1, &c, 1);
}

static	void	get_flags(const char **str, va_list ap)
{
	t_flags flags;

	init(&flags);
	check_it(str, &flags, ap);
	if ((*(*str) == '*') && (*str)++)
	{
		flags.precision = va_arg(ap, int);
		if (flags.precision < 0)
		{
			flags.precision = 0;
			flags.point = 0;
		}
	}
	if (flags.point && ft_isdigit(*(*str)))
	{
		flags.precision = ft_atoi((*str));
		while (ft_isdigit(*(*str)))
			(*str)++;
	}
	set_type(*(*str)++, &flags, ap);
}

void			set_type(char c, t_flags *flags, va_list ap)
{
	if (c == 'd' || c == 'i')
		treat_decimal(flags, va_arg(ap, int));
	else if (c == 's')
		treat_string(flags, va_arg(ap, char*));
	else if (c == 'c')
		treat_caracter(flags, (char)va_arg(ap, int));
	else if (c == 'p')
		treat_pointer(flags, va_arg(ap, size_t));
	else if (c == 'x')
		treat_h(flags, va_arg(ap, unsigned int), &c);
	else if (c == 'X')
		treat_h(flags, va_arg(ap, unsigned int), &c);
	else if (c == 'u')
		treat_unsigned(flags, va_arg(ap, unsigned int));
	else if (c == '%')
		treat_caracter(flags, c);
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;

	g_ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			get_flags(&str, ap);
		}
		else
		{
			ft_putchar(*str);
			str++;
		}
	}
	va_end(ap);
	return (g_ret);
}
