all: prog

prog: preprocessor.o utils.o comments.o headers.o
	gcc -ansi -g -Wall -pedantic -o prog preprocessor.o utils.o comments.o headers.o

preprocessor.o: preprocessor.c utils.h comments.h headers.h
	gcc -ansi -g -Wall -pedantic -c preprocessor.c


comments.o: comments.c comments.h utils.h
	gcc -ansi -g -Wall -pedantic -c comments.c


headers.o: headers.c headers.h utils.h
	gcc -ansi -g -Wall -pedantic -c headers.c


utils.o: utils.c utils.h
	gcc -ansi -g -Wall -pedantic -c utils.c

clean: 
	rm *.o  prog
