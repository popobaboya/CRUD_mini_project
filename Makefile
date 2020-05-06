Vending : main.c crud.o vendingmachine.o
	gcc -o Vending main.c curd.o vendingmachine.o

clean :
	rm *.o Vending
