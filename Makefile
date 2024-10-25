NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

LIBS = -lreadline

SRCDIR = .
BUILTIN_DIR = builtin
PARSING_DIR = parsing
ENV_DIR = env

OBJDIR = obj

SRCS = $(SRCDIR)/main.c \
       $(PARSING_DIR)/node.c \
	   $(ENV_DIR)/env.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

GRAY = \033[37m
GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo " "
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo " "
	@echo "$(GREEN)Compilation terminée -> $(NAME)$(RESET)"
	@echo " "
	@echo "$(GREEN)1 -> ./$(NAME)$(RESET)"
	@echo " "

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY)Compilation de $< -> $@$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GRAY)Répertoire $(OBJDIR) supprimé$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GRAY)Exécutable $(NAME) supprimé$(RESET)"

re: fclean all

.PHONY: all clean fclean re
