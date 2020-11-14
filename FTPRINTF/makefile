# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 11:05:17 by hgrissen          #+#    #+#              #
#    Updated: 2020/03/13 17:59:54 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OUTPUT = *.o
SRCS =	ft_printf.c\
		treat_d.c\
		treat_s.c\
		ft_atoi.c\
		ft_isdigit.c\
		treat_character.c\
		treat_h.c\
		treat_u.c\
		treat_p.c\
		ft_putstr_new.c\
		ft_strlen_p.c\
		init_flags.c\
		ft_strrevv.c\
		


all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar -rc $(NAME) *.o
	ranlib $(NAME) 

clean:
	rm -f  *.o

fclean: clean
	rm -f $(NAME)

re: fclean all