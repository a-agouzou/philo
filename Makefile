# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 16:06:29 by aagouzou          #+#    #+#              #
#    Updated: 2023/04/19 00:30:15 by aagouzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

# FLAGS= -fsanitize=thread

FILES= main.c utils.c list.c create.c routine.c monitor.c

OBJS= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -fr *.o
fclean: clean
	rm -fr $(NAME)

re: fclean all
	