#--------------------Colors---------------------

PINK            = \033[0;35m
LIGHT_PINK      = \033[0;38;5;213m
LIGHT_PURPLE    = \033[0;35m
SOFT_CYAN       = \033[0;96m
WHITE           = \033[1;37m
NC              = \033[0m
LIGHT_LAVENDER  = \033[0;150m  # Lavande pâle
MAUVE           = \033[38;5;105m

#--------------------Program--------------------

NAME            = Bureaucrat

#--------------------Compilation----------------

CC              = c++
CFLAGS          = -Wall -Wextra -Werror -std=c++98 
RM              = rm -rf

#--------------------PATHS----------------------

OBJ_PATH        = objects

#--------------------Sources--------------------

HEADERS         = $(addsuffix .hpp, \
                    Bureaucrat \
                    )

SRCS            = $(addsuffix .cpp, \
                    main \
                    Bureaucrat \
                    )

OBJS            = $(SRCS:%.cpp=$(OBJ_PATH)/%.o)

DEPS            = $(OBJS:.o=.d)

#--------------------RULES---------------------

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${LIGHT_PINK}$@ ${MAUVE}Compiled successfully${NC}"

$(OBJ_PATH)/%.o: %.cpp $(HEADERS)
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_PATH)
	@echo "${LIGHT_PURPLE}Finished cleaning${NC}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${LIGHT_PURPLE}Complete cleaning completed${NC}"

re: fclean all

-include $(DEPS)

run: $(NAME)
	@./$(NAME) file bonjour ciao

valgrind: $(NAME)
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re
