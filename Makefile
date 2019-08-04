PROGRAM_1	= push_swap
PROGRAM_2	= checker

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
FLAGS			= $(CFLAGS)

PUSH_SWAP_FILES	= push_swap.c
CHECKER_FILES	= checker.c
ALL_FILES		= $(PUSH_SWAP_FILES) $(CHECKER_FILES)

PUSH_SWAP_OBJ	= $(addprefix push_swap_build/, $(PUSH_SWAP_FILES:.c=.o))
CHECKER_OBJ		= $(addprefix checker_build/, $(CHECKER_FILES:.c=.o))

all: program1 program2

program1: $(PUSH_SWAP_OBJ)
	@echo "Creating: $(PROGRAM_1)"
	@$(CC) $(FLAGS) -I push_swap_includes $(PUSH_SWAP_OBJ) -o $(PROGRAM_1)

program2: $(CHECKER_OBJ)
	@echo "Creating: $(PROGRAM_2)"
	@$(CC) $(FLAGS) -I checker_includes $(CHECKER_OBJ) -o $(PROGRAM_2)

push_swap_build:
	@echo "  Creating build directory"
	@mkdir push_swap_build

checker_build:
	@echo "  Creating checker_build directory"
	@mkdir checker_build

push_swap_build/%.o: push_swap_sources/%.c | push_swap_build
	@echo "  Building: $@"
	@$(CC) -I includes -c $< -o $@

checker_build/%.o: checker_sources/%.c | checker_build
	@echo "  Building: $@"
	@$(CC) -I includes -c $< -o $@

clean:
	@rm -fr push_swap_build
	@rm -fr checker_build

fclean: clean
	@rm -f $(PROGRAM_1)
	@rm -f $(PROGRAM_2)

re: fclean all
