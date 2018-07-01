NAME = ft_sraka
SRC = CPU.cpp DateTime.cpp Hostname.cpp OS.cpp RAM.cpp main.cpp
SDL2_F	= -F frameworks/ \
	-framework SDL2 -framework SDL2_image -framework SDL2_ttf
SDL2_P	= -rpath frameworks/
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = objects
CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98 -O3 \
	-I frameworks/SDL2.framework/Headers/ \
	-I frameworks/SDL2_image.framework/SDL2_image/Headers \
	-I /Library/Frameworks/SDL2.framework/Versions/Current/Headers

INCLUDES = -lncurses $(ncursesw5-config --cflags --libs)\

all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES) $(SDL2_P) $(SDL2_F)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all