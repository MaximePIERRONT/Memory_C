but : Main

OFILES = main.o \
		 play.o \
		 generation.o

CC = gcc
CFLAGS = -ansi

#--------------------------------

main.o : generation.h play.h

play.o : generation.h play.h

generation.o : generation.h

#--------------------------------

Main : $(OFILES)
		$(CC) -o Main $(OFILES) -lgraph $(CFLAGS)

clean :
	-rm -f $(OFILES) Main

run :
	./Main

.PHONY : but clean run


