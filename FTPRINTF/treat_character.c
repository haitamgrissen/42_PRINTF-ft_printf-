/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:00:18 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 11:00:22 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_normal(t_flags *flags, char c)
{
	flags->minwidth -= 1;
	while (flags->minwidth > 0 && (flags->minwidth--))
		(flags->zero) ? ft_putchar('0') : ft_putchar(' ');
	if (!c)
		ft_putchar(0);
	else
		ft_putchar(c);
}

void	char_minus(t_flags *flags, char c)
{
	flags->minwidth -= 1;
	if (!c)
	{
		ft_putchar(0);
		while (flags->minwidth > 0 && (flags->minwidth--))
			ft_putchar(' ');
	}
	else
	{
		ft_putchar(c);
		while (flags->minwidth > 0 && (flags->minwidth--))
			ft_putchar(' ');
	}
}

void	treat_caracter(t_flags *flags, char c)
{
	if (flags->minus)
		char_minus(flags, c);
	else
		char_normal(flags, c);
}
