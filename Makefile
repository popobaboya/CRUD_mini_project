Vending : main.c crud.o
	gcc -o Vending main.c crud.o

clean :
	rm *.o Vending
