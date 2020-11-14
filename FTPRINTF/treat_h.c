/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:01:39 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 18:04:34 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

char	*ft_strrev(char *str)
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

char	*dtoh(unsigned long nb, char type)
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
	ft_strrev(hexa);
	return (hexa);
}

void	normal_h(t_flags *flags, char *ptr)
{
	while (flags->minwidth > 0 && (flags->minwidth--))
		(flags->zero && !flags->point) ? ft_putchar('0') : ft_putchar(' ');
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	ft_putstr_flaged(ptr, flags);
}

void	minus_h(t_flags *flags, char *ptr)
{
	while (flags->precision > 0 && (flags->precision--))
		ft_putchar('0');
	if (!(flags->point && !flags->precision && *ptr == '0'))
		ft_putstr_flaged(ptr, flags);
	while (flags->minwidth > 0 && (flags->minwidth--))
		ft_putchar(' ');
}

void	treat_h(t_flags *flags, unsigned int nb, const char *s)
{
	int		len;
	char	*ptr;

	ptr = (char *)s;
	if (*s == 'x')
		ptr = dtoh(nb, 'x');
	else if (*s == 'X')
		ptr = dtoh(nb, 'X');
	len = ft_strlennn(ptr, flags);
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
		minus_h(flags, ptr);
	else
		normal_h(flags, ptr);
	free(ptr);
}
