Vending : main.c crud.o vendingMachine.o
	gcc -o Vending main.c crud.o vendingMachine.o

clean :
	rm *.o Vending
