SERVER		= server
CLIENT		= client
LIBFT		= libft/libft.a

MSG_LEN		= 1000

MSG			= cat /dev/urandom | base64 | head -c $(MSG_LEN)
#openssl rand -base64 $(MSG_LEN)

CFLAG		= -Wall -Wextra -Werror -O2
INC_PATH	= libft/inc

SRC_SERVER	= server.c
OBJ_SERVER	= $(SRC_SERVER:.c=.o)

SRC_CLIENT	= client.c
OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

all:		$(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make -C libft

$(SERVER):	$(OBJ_SERVER) $(LIBFT)
	gcc $(OBJ_SERVER) -L./libft -lft -o $@

$(CLIENT):	$(OBJ_CLIENT) $(LIBFT)
	gcc $(OBJ_CLIENT) -L./libft -lft -o $@

%.o:		%.c
	gcc $(CFLAG) -I $(INC_PATH) -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean:		clean
	@make fclean -C libft
	rm -f $(SERVER) $(CLIENT)

re:			fclean all

norm:
	@make norm -C libft
	@norminette $(SRC_SERVER) $(SRC_CLIENT) | grep -v "OK!"

pkill:
	@-pkill server

rs:			server pkill
	./server &

rc:			client
	./client $$(pgrep -xn server | head -n 1 | cut -d ' ' -f 2) "$$($(MSG))" &

test:		rs rc

.PHONY:		all clean fclean re norm pkill rs rc test
