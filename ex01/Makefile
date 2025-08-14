# =================== #
#     VARIABLES       #
# =================== #

NAME = Phonebook
COMPILE = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Ihpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	cpp/main.cpp \
		cpp/Phonebook.cpp \
		cpp/Contact.cpp \
		cpp/Add.cpp \
		cpp/Search.cpp \
		cpp/Messages.cpp \
		cpp/Utils.cpp \

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