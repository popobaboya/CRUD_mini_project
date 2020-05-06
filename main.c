#include "vendingMachine.h"

int main(void){
	Coin coin;
	coin.baekwon=10;
	coin.o_baekwon=10;

	char password[5]="0000";
	bool consumer= true;	
	bool exit=false; //if exit is 'true', end the program.

	//count= loadData();

	while(exit==false){
        	int menu;
		//printf("password: %s\n",password);
		while(consumer==true){
			
			menu= listConsumer();	

			if(menu==1){

			}
			else if(menu==2){

			}
			else if(menu==3){
				consumer=false;
				break;
			}
			else if(menu== 0){
				exit= true;
				break;
			}

		}
		while(consumer==false){
			char input_password[4];
			
			if(!(strcmp(password,"0000"))){
				
    				printf("\n===============================\n");
				printf("Write password (4 numbers except 0000) >>");
				scanf("%s",password);
				printf(">>Completed!\n");

    				printf("===============================\n");
			}
			else{
				
    				printf("\n===============================\n");
				printf("Write Password >>");
				scanf("%s",input_password);
				if(!(strcmp(input_password, password))){
					printf("**You can't enter Administrator Mode\n");
    					printf("===============================\n");
					consumer=true;
  					break;
				}

			}
			menu= listAdministrator();
			if(menu== 1){
				
			}
			if(menu== 2){
				
			}
			if(menu== 3){
				
			}
			if(menu== 4){
				
			}
			if(menu== 5){
				
			}
			else if(menu==6){
				printf("\n*Change Password*\n");
				changePassword(password);
			}
            		else if(menu==7){
    				coin.total_won= (coin.baekwon*100) + (coin.o_baekwon*500);
                		printf("\n*Check coin Amount*\n");
    				printf("===============================\n");
                		printf("Number of 100 won: %d\n",coin.baekwon);
                		printf("Number of 500 won: %d\n",coin.o_baekwon);
                		printf("Total Price: %d\n",coin.total_won);
    				printf("===============================\n");

            		}
            		else if(menu==8){
				coinRefill(&coin);
            		}
			else if(menu== 9){
				consumer=true;
				break;
			}
			else if(menu== 10){
				exit=true;
				break;
			}
		}

	}	
	return 0;	
}

