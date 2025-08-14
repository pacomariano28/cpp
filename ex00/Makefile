#     VARIABLES       #

NAME = megaphone
COMPILE = g++
FLAGS = -std=c++98 #-Wall -Wextra -Werror
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

#      SOURCES       #

SRC = megaphone.cpp

#     TARGETS       #

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMPILE) $(FLAGS) -o $@ $^

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	@rm -rf obj/

fclean: clean
	@rm $(NAME)

re: fclean all
