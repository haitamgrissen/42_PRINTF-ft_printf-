/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:03:46 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 11:04:00 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_u(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int		digitlenghtt(unsigned int i)
{
	int a;

	a = 0;
	while (i != 0)
	{
		i = i / 10;
		a++;
	}
	return (a);
}

void	normal_u(t_flags *flags, unsigned int nbr)
{
	while (flags->minwidth > 0 && (flags->minwidth--))
		(flags->zero && !flags->point) ? ft_putchar('0') : ft_putchar(' ');
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	if (!(flags->point && !flags->precision && nbr == 0))
		ft_putnbr_u(nbr);
}

void	minus_u(t_flags *flags, unsigned int nbr)
{
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	if (!(flags->point && !flags->precision && nbr == 0))
		ft_putnbr_u(nbr);
	while (flags->minwidth > 0 && (flags->minwidth--))
		ft_putchar(' ');
}

void	treat_unsigned(t_flags *flags, unsigned int nb)
{
	int len;

	len = digitlenghtt(nb);
	if (flags->point)
		(flags->precision < len) && (flags->precision = len);
	if (flags->precision)
		((flags->minwidth -= flags->precision) < 0) ? flags->minwidth = 0 : 0;
	(nb <= 0) && (flags->minwidth--);
	(nb == 0) && (flags->point) && (flags->minwidth++);
	if (flags->minwidth && !flags->precision && (flags->minwidth -= len))
		(flags->minwidth < 0) ? flags->minwidth = 0 : 0;
	(flags->precision) ? flags->precision -= len : 0;
	if (flags->minus)
		minus_u(flags, nb);
	else
		normal_u(flags, nb);
}
