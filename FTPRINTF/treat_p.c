/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:02:41 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 12:04:56 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dtohx(size_t nb, char type)
{
	char	*hexa;
	int		i;
	int		rest;

	i = 0;
	hexa = (char *)malloc(sizeof(char) * 17);
	if (nb == 0)
		hexa[i++] = '0';
	else
		while (nb != 0)
		{
			rest = (nb % 16);
			if (rest < 10)
				hexa[i] = rest + 48;
			else if (type == 'X')
				hexa[i] = rest + 55;
			else if (type == 'x')
				hexa[i] = rest + 87;
			nb = nb / 16;
			i++;
		}
	hexa[i] = '\0';
	ft_strrevv(hexa);
	return (hexa);
}

int		ft_strlennnn(char *str, t_flags *flags)
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

void	minus_poin(t_flags *flags, char *p)
{
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	ft_putstr_flaged_new("0x");
	if (!(flags->point && !flags->precision && *p == '0'))
		ft_putstr_flaged(p, flags);
	while (flags->minwidth > 0 && (flags->minwidth--))
		ft_putchar(' ');
}

void	normal_poin(t_flags *flags, char *p)
{
	while (flags->minwidth > 0 && (flags->minwidth--))
		(flags->zero && !flags->point) ? ft_putchar('0') : ft_putchar(' ');
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	ft_putstr_flaged_new("0x");
	ft_putstr_flaged(p, flags);
}

void	treat_pointer(t_flags *flags, size_t num)
{
	char	*p;
	int		len;

	len = 0;
	p = dtohx(num, 'x');
	len += ft_strlennnn(p, flags) + 2;
	if (flags->point)
		(flags->precision < len) && (flags->precision = len);
	if (flags->precision)
		((flags->minwidth -= flags->precision) < 0) ? flags->minwidth = 0 : 0;
	(num <= 0) && (flags->minwidth--);
	(num == 0) && (flags->point) && (flags->minwidth++);
	if (flags->minwidth && !flags->precision && (flags->minwidth -= len))
		(flags->minwidth < 0) ? flags->minwidth = 0 : 0;
	(flags->precision) ? flags->precision -= len : 0;
	if (flags->minus)
		minus_poin(flags, p);
	else
		normal_poin(flags, p);
	free(p);
}
