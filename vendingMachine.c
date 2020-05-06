#include "vendingMachine.h"

int listConsumer(){
	int menu;

	printf("\n**Consumer Mode**\n");
	printf("===============================\n");
	printf("1. Check Product List\n");
	printf("2. Buy Product\n");
	printf("3. Go to Administrator Mode\n");
	printf("0. Exit\n");
	printf("===============================\n");
	printf("Which menu do you choose? (number)>>");
	scanf("%d",&menu);

	return menu;
}

int listAdministrator(){
	int menu;

	printf("\n**Administrator Mode**\n");
	printf("===============================\n");
	printf("1. Check Product List\n");
	printf("2. Update Product Information\n");
	printf("3. Delete Product\n");
	printf("4. Add Prduct\n");
	printf("5. Search Product\n");
	printf("6. Change Password\n");
	printf("7. Check Coin Amount\n");
	printf("8. Refill Coin\n");
	printf("9. Go to Consumer Mode\n");
	printf("0. exit\n");
	printf("===============================\n");
	printf("Which menu do you choose? (number)>>");
	scanf("%d",&menu);
	
	return menu;
}

int coinRefill(Coin *coin){
	int amount;
	printf("How many coins do you want to refill?\n");
	printf("for 100 won >>");
	scanf("%d",&amount);
	coin->baekwon= coin->baekwon +amount;

	printf("for 500 won >>");
	scanf("%d",&amount);
	coin->o_baekwon= coin->o_baekwon + amount;
	
	return 0;
}

int changePassword(char* password){
	char newpassword[5];
	char check_new[5];
	printf("Write New Password >>");
	scanf("%s",newpassword);
	printf("Write New Password Again >>");
	scanf("%s",check_new);
	if(strcmp(newpassword, check_new)){
		printf("Wrong number!! fail to change..\n");
		return 1;
	}
	else{
		for(int i=0; i<5; i++){
			password[i]= newpassword[i];
		}
		
		printf("Password Changed!");
		return 0;
	}
}