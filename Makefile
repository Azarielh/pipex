# MANQUE  :
#       SUPPRIMER LIBFT.A DU DOSSIER COURANT
#           "     LIBFT.H DU DOSSIER COURANT

.PHONY: all clean fclean re

# General 
CFLAGS = -Wall -Wextra -Werror -g3
NAME = pipex

#___________ SRCS _____________

SRC = pipex.c\
	utils.c\
	ft_split2.c\
	execute.c

OBJS = $(SRC:.c=.o)

# Setting up an custom error message
ERROR_MSG = "$(RED)[ERROR] Compilation failed$(RESET)"

all: $(NAME)

%.o: %.c pipex.h libft.h Makefile
	@echo -n "$(BLUE) $@ $(RESET)"
	@cc $(CFLAGS) -I . $< -c -o $@ && echo "$(GREEN)>>> SUCCESS $(RESET)" || { echo "$(ERROR_MSG)"; exit 1; }

$(NAME): $(OBJS) $(LIBFT_A)
	@cc $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)======================= All pipex required library has been compiled =======================$(RESET)"

$(LIBFT_A):
	@echo "$(YELLOW)1/  Building libft..............................................................................$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory || @echo "Issue while attempting compiling libft"
	@cp $(LIBFT_DIR)libft.a ./ && cp $(LIBFT_DIR)libft.h ./

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean
	@rm -f $(OBJS)

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean
	@rm -f $(NAME)

re: fclean all


# _____________________ LIBFT DIRECTORIES __________________________

# LIBFT
LIBFT_DIR = libft/
LIBFT_A = libft/libft.a

DIR_BOOLEAN = libft/boolean/ft_isalnum.c\
		libft/boolean/ft_isalpha.c\
		libft/boolean/ft_isascii.c\
		libft/boolean/ft_isdigit.c\
		libft/boolean/ft_isprint.c\
		libft/boolean/ft_are_u_1_of_u.c
DIR_FINDER = libft/finder/ft_strchr.c\
		libft/finder/ft_strrchr.c\
		libft/finder/ft_strnstr.c\
		libft/finder/ft_substr.c

DIR_STR_MANIPULATION = libft/str_manipulation/ft_strjoin.c\
		libft/str_manipulation/ft_strtrim.c\
		libft/str_manipulation/ft_split.c\
		libft/str_manipulation/ft_strmapi.c\
		libft/str_manipulation/ft_striteri.c\
		libft/str_manipulation/ft_strlcpy.c\
		libft/str_manipulation/ft_strlcat.c\
		libft/str_manipulation/ft_strdup.c\
		libft/str_manipulation/ft_putendl_fd.c


DIR_STR_ANALYSIS = libft/str_analysis/ft_strlen.c\
		libft/str_analysis/ft_strncmp.c\

DIR_CONVERTION = libft/convertion/ft_atoi.c\
		libft/convertion/ft_itoa.c\
		libft/convertion/ft_tolower.c\
		libft/convertion/ft_toupper.c\

DIR_MEMORY = libft/memory/ft_bzero.c\
		libft/memory/ft_memchr.c\
		libft/memory/ft_memcmp.c\
		libft/memory/ft_memmove.c\
		libft/memory/ft_memset.c \
		libft/memory/ft_memcpy.c\
		libft/memory/ft_calloc.c\

DIR_OUTPUT = libft/output/ft_putchar_fd.c\
		libft/output/ft_puthex.c\
		libft/output/ft_putnbr_deci.c\
		libft/output/ft_putstr_fd.c\
		libft/output/ft_putnbr_fd.c\
		libft/output/ft_printf.c\

DIR_LIST = libft/list/ft_lstnew.c\
		libft/list/ft_lstadd_front.c\
		libft/list/ft_lstadd_back.c\
		libft/list/ft_lstclear.c\
		libft/list/ft_lstdelone.c\
		libft/list/ft_lstiter.c\
		libft/list/ft_lstlast.c\
		libft/list/ft_lstmap.c\
		libft/list/ft_lstsize.c

DIR_GNL = libft/gnl/get_next_line_bonus.c\
		libft/gnl/get_next_line_utils_bonus.c
# Define the source files
LIBFT_SRCS = $(DIR_BOOLEAN) $(DIR_FINDER) $(DIR_STR_MANIPULATION) $(DIR_STR_ANALYSIS) $(DIR_CONVERTION) $(DIR_MEMORY) $(DIR_OUTPUT) $(DIR_LIST) $(DIR_GNL)

# __________________ Color codes ___________________________

RESET      = \033[0m
RED        = \033[31m
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
MAGENTA    = \033[35m
CYAN       = \033[36m
WHITE      = \033[37m
BOLD       = \033[1m