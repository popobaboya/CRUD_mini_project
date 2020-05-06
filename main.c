#include "crud.h"
#include "vendingMachine.h"

int main(void){
	Product *sp[30];
	int count=0;
	int curi =0;
	int check=0;
	Coin coin;
	coin.baekwon=10;
	coin.o_baekwon=10;

	char password[5]="0000";
	bool consumer= true;	//if customer is true -> customer mode, else administrator mode
	bool exit=false; //if exit is 'true', end the program.

	printf("***Vending Mahcine***\n");
    sp[count]=(Product*)malloc(sizeof(Product));
	
	count= loadData(&sp[0]); //'count' increases if there are datas in 'product.txt'
	printf("count: %d\n",count);

	while(exit==false){
        int menu;
		//printf("password: %s\n",password);
		
		while(consumer==true){

			menu= listConsumer();	

			if(menu==1){
    			        if(count<=0){ 
               				printf("There is no data!\n");
                			continue;
            			}
				loopRead(sp, curi);
			}
			else if(menu==2){
				int num;
				int price;
				int change_obaek; //ÀÜµ·À¸·Î °Å½½·¯ÁÙ 500¿øÀÇ °¹¼ö
				int change_baek;
				int money;

				printf("**Buy Product**\n");
				num=selectNum(sp, curi);
 				price= sp[num-1]->cost;
			
				printf("How much will you put?(Please write in KRW(won))>>");
				scanf("%d",&money);

				if(price > money){
					printf("*Not Enough Money..\n");
					continue;
				}
				sp[num-1]->count--;

				money= money - price;
				change_obaek= money/500;
				change_baek= (money%500)/100;

				coin.baekwon= coin.baekwon - change_baek;
				coin.o_baekwon= coin.o_baekwon - change_obaek;
				coin.total_won= coin.total_won -price;
			    
				if(coin.o_baekwon < 0 || coin.baekwon < 0){
        			printf("*Sorry..I don't have enough change..\n");
			    }else{
        			printf(">>Change: %d 100 won and %d 500 won\n",change_baek , change_obaek);
			    }

			}
			else if(menu==3){
				consumer=false;
				check = 0;
				break;
			}
			else if(menu== 0){
				exit= true;
				break;
			}

		}
		while(consumer==false&&exit==false){
		 if(check==0){
			char input_password[4];
			
			if(strcmp(password,"0000")==0){
				
    				printf("\n===============================\n");
					printf("Write password (4 numbers except 0000) >>");
					scanf("%s",password);
					printf(">>Completed!\n");
    				printf("===============================\n");
					check = 1;
			}
			else{
				//printf("password: %s\n",password);
    			printf("\n===============================\n");
				printf("Write Password >>");
				scanf("%s",input_password);
				check = 1;
				if(strcmp(input_password, password)!=0){
					printf("**You can't enter Administrator Mode\n");
    					printf("===============================\n");
					consumer=true;
  					break;
				}

			}
		 }
			menu= listAdministrator();
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
			else if(menu== 0){
				exit=true;
				break;
			}
		}

	}
	saveData(&sp[0], count);

	return 0;	
}