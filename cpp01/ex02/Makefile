# =================== #
#     VARIABLES       #
# =================== #

NAME = Zombie
COMPILE = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Ihpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	main.cpp \

# ================= #
#     TARGETS       #
# ================= #

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