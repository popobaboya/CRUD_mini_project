#include "crud.h"
#include "vendingMachine.h"


void buyProduct(Product *p[], Coin *coin, int curi);

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
	
	count= loadData(sp); //'count' increases if there are datas in 'product.txt'
	curi = count;
	printf("count: %d\n",count);

	while(exit==false){
        int menu;
		//printf("password: %s\n",password);
		
		while(consumer==true){

			menu= listConsumer();	

			if(menu==1){
    			        if(count<=0){ 
               				printf("There is no products!\n");
                			continue;
            			}
				loopRead(sp, curi);
			}
			else if(menu==2){

    			        if(count<=0){ 
               				printf("There is no products!\n");
                			continue;
            			}
				buyProduct(sp, &coin, curi);

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
					printf("Write password for initialize (4 numbers except 0000) >>");
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
					printf("The password is wrong\n");
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
			else if(menu == 10){
			 saveData(&sp[0],count);
			}
			else if(menu== 0){
				exit=true;
				break;
			}
		}

	}


	return 0;	
}


void buyProduct(Product *p[], Coin *coin, int curi){
 int num=0;
 int count=0;
 int cost_t=0;
 int money=0;
 int money_t=0;
 int change=0;
 int ch_100=0;
 int ch_500=0;
 num = selectNum(p, curi);
 if(num==0){
  printf("Canceled!\n");
  return;
 }
 while(p[num-1]->quantity<=0){
  printf("That is sold out!\n");
  printf("Please choose other one\n");
  num = selectNum(p, curi);
  if(num==0){
   printf("Canceled!\n");
   return;
  }
 }
 printf("How many do you want? : ");
 scanf("%d", &count);
 while(count>p[num-1]->quantity){
  printf("The product's maximum quantity is %d!\n", p[num-1]->quantity);
  printf("How many do you want? : ");
  scanf("%d", &count);
 }

 cost_t = p[num-1]->cost * count;
 printf("Total cost is %d\n", cost_t);
 printf("Please insert money : ");
 scanf("%d", &money);
 money_t = money;

 while(money_t<cost_t){
  printf("Total cost is %d, you inserted %d\n", cost_t, money);
  printf("Please insert more money :\n");
  scanf("%d", &money);
  money_t += money;
 }

 change = money_t - cost_t;
 ch_500 = change/500;
 ch_100 = (change%500)/100; 
 if(coin->o_baekwon-ch_500 < 0 || coin->baekwon-ch_100 < 0){
	printf("Sorry! There is not enough coin for change!\n");
	printf("Please contact to administrator\n");
	return;
 }
 
 printf("\nHere are the products you picked, %d of %s\n", count, p[num-1]->name);
 printf("The change is %d, %d of 500won and %d of 100won\n", change, ch_500, ch_100);
 printf("Thank you for using!\n");
 
 p[num-1]->quantity -= count;
 coin->o_baekwon -= ch_500;
 coin->baekwon -= ch_100;
 coin->total_won = coin->o_baekwon*500 + coin->baekwon*100;
}

