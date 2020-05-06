#include "crud.h"

typedef int bool;
enum{false, true};

int coint_refill(int *baekwon, int * o_baekwon);
int change_password(char password[]);
//int saveData(Product p[], *p);
//int loadData(Product *p);

void listConsumer();
void listAdministrator();

int main(void){
	Product *sp[30];
	int count=0;
	int curi =0;
	int baekwon=10;
	int o_baekwon=10;
	char password[5]="0000";
	bool consumer= true;
    int total_won;
    total_won= (baekwon*100) + (o_baekwon*500);
	
	int count;
	bool exit=false; //if exit is 'true', end the program.

	//count= loadData();

	while(exit==false){
        printf("password: %s\n",password);
		while(consumer==true){
			int menu;
			printf("\n**Consumer Mode**\n");
			printf("===============================\n");
			printf("1. Check Product List\n");
			printf("2. Buy Product\n");
			printf("3. Go to Administrator Mode\n");
			printf("4. Exit\n");
			printf("===============================\n");
			printf("Which menu do you choose? (number)>>");
			scanf("%d",&menu);


			if(menu==1){
    			        if(count<=0){ 
               				printf("There is no data!\n");
                			continue;
            			}
				loopRead(sp, curi);
			}
			else if(menu==2){

			}
			else if(menu==3){
				consumer=false;
				break;
			}
			else if(menu== 4){
				exit= true;
				break;
			}

		}
		while(consumer==false){
			int menu;
			char input_password[4];
			if(!(strcmp(password,"0000"))){
				printf("\nWrite password (4 numbers except 0000) >>");
				scanf("%s",password);
				printf(">>Completed!\n");
			}
			else{
				printf("\nWrite Password >>");
				scanf("%s",input_password);
				if(strcmp(input_password, password)){
					printf("**You can't enter Administrator Mode\n");
                    consumer=true;
                    break;
				}

			}
			printf("\n**Administrator Mode**\n");
			printf("===============================\n");
			printf("1. Check Product List\n");
			printf("2. Update Product Information\n");
			printf("3. Delete Product\n");
			printf("4. Add Prduct\n");
			printf("5. Search Product\n");
	       	 	printf("6. Check Coin Amount\n");
        	 	printf("7. Refill Coin\n");
			printf("8. Go to Consumer Mode\n");
			printf("9. exit\n");
			printf("===============================\n");
			printf("Which menu do you choose? (number)>>");
			scanf("%d",&menu);

			if(menu== 1){
    			        if(count<=0){ 
               				printf("There is no data!\n");
                			continue;
            			}
				loopRead(sp, curi);
			 	
			}
			if(menu== 2){
    			        if(count<=0){ 
               				printf("There is no data!\n");
                			continue;
            			}
				updateProduct(sp, curi);
				
			}
			if(menu== 3){
    			        if(count<=0){ 
               				printf("There is no data!\n");
                			continue;
            			}
				deleteProduct(sp, curi);
				count--;
			}
			if(menu== 4){
				sp[curi]=(Product*)malloc(sizeof(Product));
				count += addProduct(sp[curi++]);
				printf("Added!\n");
			}
			if(menu== 5){
				
			}
            else if(menu==6){
                printf("\n*Check coin Amount*\n");
    			printf("===============================\n");
                printf("Number of 100 won: %d\n",baekwon);
                printf("Number of 500 won: %d\n",o_baekwon);
                printf("Total Price: %d\n",total_won);
    			printf("===============================\n");

            }
            else if(menu==7){

            }
			if(menu== 8){
				consumer=true;
				break;
			}
			if(menu== 9){
				exit=true;
				break;
			}
		}

	}	
	return 0;	
}

