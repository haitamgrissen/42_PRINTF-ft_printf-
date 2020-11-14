/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:00:41 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 18:05:27 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		digitlenght(int i)
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

void	ft_putnbr(int nb)
{
	unsigned int i;

	i = 0;
	if (nb >= 0)
		i = nb;
	if (nb < 0)
		i = nb * -1;
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar((i % 10) + '0');
}

void	minus(t_flags *flags, int nbr, long pos)
{
	if ((nbr < 0) && (!flags->check) && (flags->check = 1))
		ft_putchar('-');
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	if (!(flags->point && !flags->precision && nbr == 0))
		(flags->check) ? ft_putnbr(pos) : ft_putnbr(nbr);
	while (flags->minwidth > 0 && (flags->minwidth--))
		ft_putchar(' ');
}

void	normal(t_flags *flags, int nbr, long pos)
{
	if ((nbr < 0) && flags->zero && !flags->point
		&& (!flags->check) && (flags->check = 1))
		ft_putchar('-');
	while (flags->minwidth > 0 && (flags->minwidth--))
		(flags->zero && !flags->point) ? ft_putchar('0') : ft_putchar(' ');
	if ((nbr < 0) && (!flags->check) && (flags->check = 1))
		ft_putchar('-');
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	if (!(flags->point && !flags->precision && nbr == 0))
		(flags->check) ? ft_putnbr(pos) : ft_putnbr(nbr);
}

void	treat_decimal(t_flags *flags, int nbr)
{
	long	pos;
	int		len;

	pos = nbr * (-1);
	len = digitlenght(nbr);
	if (flags->point)
		(flags->precision < len) && (flags->precision = len);
	if (flags->precision)
		((flags->minwidth -= flags->precision) < 0) ? flags->minwidth = 0 : 0;
	else if (((nbr < 0) && flags->point) && (flags->check = 1))
		ft_putchar('-');
	(nbr <= 0) && (flags->minwidth--);
	(nbr == 0) && (flags->point) && (flags->minwidth++);
	if (flags->minwidth && !flags->precision && (flags->minwidth -= len))
		(flags->minwidth < 0) ? flags->minwidth = 0 : 0;
	(flags->precision) ? flags->precision -= len : 0;
	if (flags->minus)
		minus(flags, nbr, pos);
	else
		normal(flags, nbr, pos);
}
