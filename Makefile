CC = gcc

NAME = push_swap.a

PROGRAM = push_swap

LIST =	ft_move_to_a.c ft_replace.c ft_count_argv.c ft_sb.c ft_rb.c ft_ss.c ft_rrb.c ft_sort_many_add.c ft_plus_first.c ft_minus_first.c ft_split_atoi.c ft_printf.c ft_putchar.c ft_putnbr_fd.c push_swap.c ft_is_sorted.c ft_sort.c ft_print_stack.c ft_sort_four.c ft_sort_three.c ft_sort_many.c ft_sort_two.c ft_nearest.c ft_pa.c ft_pb.c ft_ra.c ft_rra.c ft_sa.c ft_strjoin.c ft_strlen.c ft_calloc.c 

HEADER = push_swap.h

OBJ	=	$(LIST:.c=.o)

FLAGS	=	-Wall -Wextra -Werror -g
OPTFLAGS	=	-O2

all:	$(PROGRAM)

$(PROGRAM):	$(NAME)
	@$(CC) -o $(PROGRAM) $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

.c.o:	$(LIST)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	-@rm $(OBJ) 2>/dev/null || true

fclean:clean
	-@rm $(NAME) $(PROGRAM) 2>/dev/null || true

re:	fclean all

re_bonus:	fclean bonus

.PHONY:	all clean fclean re re_bonus