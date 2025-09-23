# =================== #
#     VARIABLES       #
# =================== #

NAME = Buro
COMPILE = c++
FLAGS = -std=c++98 -Ihpp -Werror -Wall -Wextra
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	main.cpp \
		Bureaucrat/Bureaucrat.cpp \
		AForm/AForm.cpp \

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