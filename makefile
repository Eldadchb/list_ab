list_ab: list_ab.o
	gcc -ansi -Wall -pedantic list_ab.o -o list_ab
	
list_ab.o: list_ab.c
	gcc -c -ansi -Wall -pedantic list_ab.c -o list_ab.o
