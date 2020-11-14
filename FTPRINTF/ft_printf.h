/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 10:57:56 by hgrissen          #+#    #+#             */
/*   Updated: 2020/03/13 18:02:14 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		g_ret;
typedef struct	s_flags
{
	int minus;
	int zero;
	int minwidth;
	int point;
	int precision;
	int check;
}				t_flags;

int				ft_printf(const char *str, ...);
void			ft_putchar(char c);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			treat_decimal(t_flags *flags, int nbr);
void			set_type(char c, t_flags *flags, va_list ap);
void			treat_string(t_flags *flags, char *str);
void			treat_caracter(t_flags *flags, char c);
void			treat_h(t_flags *flags, unsigned int nb, const char *s);
void			treat_unsigned(t_flags *flags, unsigned int nb);
char			*pointeur(void *p, t_flags *flags);
void			treat_pointer(t_flags *flags, size_t num);
void			ft_putstr_flaged_new(char *str);
int				ft_strlen_p(char *str);
void			init(t_flags *flags);
void			check_it(const char	**str, t_flags *flags, va_list ap);
void			ft_putstr_flaged(char *str, t_flags *flags);
int				ft_strlennn(char *str, t_flags *flags);
char			*ft_strrevv(char *str);
void			ft_putstr_flaged(char *str, t_flags *flags);

#endif
