##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_ASM		=	asm/

PATH_COREWAR	=	corewar/


################# COMPILATION #################
all:
	make -C	$(PATH_ASM)
	make -C	$(PATH_COREWAR)

re:	fclean all

clean:
	@(make clean -C $(PATH_ASM)) > /dev/null
	@(make clean -C $(PATH_COREWAR)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_ASM)) > /dev/null
	@(make fclean -C $(PATH_COREWAR)) > /dev/null

debug:
	@(make debug -C $(PATH_ASM)) > /dev/null
	@(make debug -C $(PATH_COREWAR)) > /dev/null

tests_run: all
	./tests/tester.sh