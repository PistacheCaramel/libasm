NAME    = libasm.a

SRCS    = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s #ft_stryo.s
OBJS    = $(SRCS:.s=.o)

LD        = ld

AS        = nasm
ASFLAGS    = -f elf64
TSFLAGS    = -g 
CC        = cc
CPATH    = .
CFLAGS    = -m64 -Wall -Wextra -Werror -g 
MAIN    = main.c

all:    $(NAME)

#linke les .o generes par la regle %.o

$(NAME):    $(OBJS)
	ar rcs $@ $(OBJS) 
	@ranlib $(NAME)

#definit la regle de compilation a effectuer pour chaque fichier,
#les uns apres les autres
%.o:	%.s
	$(AS) $(ASFLAGS) $(TSFLAGS) $< -o $@ 


#pour avoir dirctement tous les tests prets a etre executes :
# -L. cherche une librairie dans le repertroire courant
# -lasm permet de specifier qu on lie une librairie asm
testing:	$(NAME) $(MAIN)
	$(CC) $(CFLAGS) -o $@ $(MAIN) -L$(CPATH) -lasm  
clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME) testing

re:	fclean
	make

.PHONY    :    all fclean clean re test
