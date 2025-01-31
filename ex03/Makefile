CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	Intern
FILES	=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ		=	$(FILES:.cpp=.o)

# Règle principale
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers .o à partir des fichiers .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJ) $(wildcard *.gch)

# Suppression des objets et de l'exécutable
fclean: clean
	$(RM) $(NAME)

# Re-compilation complète
re: fclean all
