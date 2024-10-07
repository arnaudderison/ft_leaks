NAME = libft_leaks.a
CC = gcc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include

# Détection du système d'exploitation
UNAME_S := $(shell uname -s)

# Configuration de l'echo selon le système
ifeq ($(UNAME_S),Linux)
    ECHO := echo -e
else
    ECHO := echo
endif

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
CYAN := \033[0;36m
NC := \033[0m

# ft_leaks utils
FTLEAKS_UTILS = $(addprefix utils/, ft_putstr_fd.c ft_strlen.c)

# ft_leaks
LEAKS_SRC = ft_leaks.c

# ft_leaks sources
LEAKS = $(addprefix src/, $(FTLEAKS_UTILS) $(LEAKS_SRC))
LEAKS_OBJS = $(LEAKS:%.c=$(OBJ_DIR)/%.o)

# Compilation rules
all: $(NAME)

$(NAME): $(LEAKS_OBJS)
	@ar rcs $(NAME) $^
	@$(ECHO) "$(YELLOW)Library $(NAME) created.$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(ECHO) -n "\r$(CYAN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(ECHO) "$(GREEN)Object files cleaned.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@$(ECHO) "$(RED)All files removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re