NAME    = libasm.a

SRCS    = ft_strlen.s ft_strcpy.s ft_strcmp.s
OBJS    = $(SRCS:.s=.o)

AS        = nasm
ASFLAGS    = -f elf64

CC        = gcc
CFLAGS    = -m64 -Wall -Wextra -Werror -g


all:    $(NAME)

#linke les .o generes par la regle %.o
$(NAME):    $(OBJS)
	ar rcs $@ $(OBJS)


#definit la regle de compilation a effectuer pour chaque fichier,
#les uns apres les autres
%.o:	%.s
	$(AS) $(ASFLAGS) $< -o $@ 

#pour avoir dirctement tous les tests prets a etre executes :
# -L. cherche une librairie dans le repertroire courant
# -lasm permet de specifier qu on lie une librairie asm
test:	$(NAME)
	$(CC) $(CFLAGS) -o $@ main.c -L. -lasm

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME) test

re:	fclean
	make

.PHONY:	all fclean clean re test
