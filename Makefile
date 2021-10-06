CC = gcc

NAME_CLIENT = client.a
NAME_SERVER = server.a

PROGRAM_CLIENT = client
PROGRAM_SERVER = server

LIST_CLIENT = client.c ft_putnbr_fd.c ft_putstr_fd.c
LIST_SERVER = server.c ft_putnbr_fd.c ft_putstr_fd.c

OBJ_CLIENT	=	$(LIST_CLIENT:.c=.o)
OBJ_SERVER	=	$(LIST_SERVER:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all:	$(PROGRAM_CLIENT) $(PROGRAM_SERVER)

$(PROGRAM_CLIENT):	$(NAME_CLIENT)
	@$(CC) -o $(PROGRAM_CLIENT) $(NAME_CLIENT)

$(PROGRAM_SERVER):	$(NAME_SERVER)
	@$(CC) -o $(PROGRAM_SERVER) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SERVER)
	@ar rcs $(NAME_SERVER) $(OBJ_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@ar rcs $(NAME_CLIENT) $(OBJ_CLIENT)

.c.o:	$(LIST_CLIENT) $(LIST_SERVER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	-@rm $(OBJ_SERVER) $(OBJ_CLIENT) 2>/dev/null || true

fclean:clean
	-@rm $(NAME_SERVER) $(NAME_CLIENT) $(PROGRAM_SERVER) $(PROGRAM_CLIENT) 2>/dev/null || true

re:	fclean all

re_bonus:	fclean bonus

.PHONY:	all clean fclean re re_bonus