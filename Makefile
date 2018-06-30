NAME = ft_sraka
SRC = CPU.cpp DateTime.cpp Hostname.cpp OS.cpp RAM.cpp main.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = objects
CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98
INCLUDES = -lncurses $(ncursesw5-config --cflags --libs)

all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all