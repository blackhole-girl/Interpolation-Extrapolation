CC            = gcc
CFLAGS       = -ansi -Wall -Wextra -Werror
LIBS         = -lm

# ===================================================================== #
# ! - all : Compile all the executables
# ! - help : Display this help
# ! - clean : remove all the *.o and executables
# ===================================================================== #

all: polmain

help:
	@grep -E "^# !" Makefile | sed -e 's/# ! -/-/g'

clean:
	rm -f *.o polmain

polmain: polmain.o polint.o
	$(CC) $(CFLAGS)  -o polmain polmain.o polint.o $(LIBS)

polint.o: polint.c 
	$(CC) $(CFLAGS) -c polint.c 

polmain.o: polmain.c polint.h
	$(CC) $(CFLAGS) -c polmain.c 
