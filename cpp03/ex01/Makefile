# =================== #
#     VARIABLES       #
# =================== #

NAME = Scavtrap
COMPILE = c++
FLAGS = -std=c++98 -Ihpp -Werror -Wall -Wextra
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	main.cpp \
		ClapTrap/ClapTrap.cpp \
		ScavTrap/ScavTrap.cpp

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