#include "crud.h" 

int addProduct(Product *p){
 getchar();
 printf("Enter product's name : ");
 fgets(p->name,20, stdin);
 for(int i=0;i<20;i++){
 	if(p->name[i]=='\n'){
          p->name[i]='\0';
          break;
        }
 }
 printf("Enter product's weight : ");
 scanf("%d", &p->weight);
 printf("Enter product's cost : ");
 scanf("%d", &p->cost);
 printf("Enter product's quantity : ");
 scanf("%d", &p->quantity);

 return 1;
}

void readProduct(Product p){
 printf("%-12s %-9d %-9d %d\n", p.name, p.weight, p.cost, p.quantity);
}

void loopRead(Product *p[], int curi){
 int i=0;
 
 printf("\nNo Name \tWeight\tCost\tQuantity\n");
 printf("==========================================\n");
 for(i=0;i<curi;i++){
	if(p[i]==NULL) continue;
	printf("%2d ", i+1);
	readProduct(*p[i]); 
 }
}

void updateProduct(Product *p[],int curi){
 int num=0;
 num=selectNum(p, curi);
 if(num==0){
  printf("Canceled!\n");
  return;
 }

 getchar();
 printf("Enter new product's name : ");
 fgets(p[num-1]->name,20, stdin);
 for(int i=0;i<20;i++){
 	if(p[num-1]->name[i]=='\n'){
          p[num-1]->name[i]='\0';
          break;
        }
 }
 printf("Enter new product's weight : ");
 scanf("%d", &p[num-1]->weight);
 printf("Enter new product's cost : ");
 scanf("%d", &p[num-1]->cost);
 printf("Enter new product's quantity : ");
 scanf("%d", &p[num-1]->quantity); 
 printf("Updated!\n");
}

void deleteProduct(Product *p[], int curi){
 int num=0;
 num=selectNum(p, curi);
 if(num==0){
  printf("Canceled!\n");
  return;
 }
 free(p[num-1]);
 p[num-1]=NULL;
 printf("Deleted!\n");
}

int selectNum(Product *p[], int curi){
 int num=0;
 
 loopRead(p, curi);
 printf("\nWhich number do you want to select?(cancel : 0) ");
 scanf("%d", &num);
 
 return num;
}

int loadData(Product *p[]){
    int count=0;
    FILE *fp;
    fp= fopen("product.txt","rt");
    if(fp==NULL){
        printf("=> No Data!!\n");
        return 0;
    }
    
    for(;;count++){
	p[count] = (Product*)malloc(sizeof(Product));
        fscanf(fp,"%d %d %d %[^\n]s", &p[count]-> weight, &p[count]-> cost, &p[count]-> quantity, p[count]-> name);
 	if(feof(fp)) break;
    }
    fclose(fp);

    printf("=> Loading Completed! \n");

    return count;
}

void saveData(Product *p[], int count){
    FILE *fp;
    fp= fopen("product.txt","wt");

    for(int i=0; i<count; i++){
        if(p[i]!=NULL)
          fprintf(fp,"%d %d %d %s\n", p[i]-> weight, p[i]-> cost, p[i]-> quantity, p[i]-> name);
    }
 fclose(fp);

 printf("Saved!\n");
}
