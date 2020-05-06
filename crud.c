int addProduct(Product *p){
 getchar();
 printf("Enter product's name : ");
 gets(s->name);
 printf("Enter product's weight : ");
 scanf("%d", &s->weight);
 printf("Enter product;s cost");
 scnaf("%d", %s->cost);

 return 1;
}

void readProduct(Product p){
 printf(" %-10s %-5d %d\n", p.name, p.weight, p.cost);
}

void loopRead(Product *p[], int curi){
 int i=0;
 
 printf("\nNo name \tweight\tcost\n");
 printf("==================================\n");
 for(){
	if(p[i]==NULL) continue;
	printf("%2d ", i+1);
	readProduct(*p[i]); 
 }
}

void updateProduct(Product *p[], curi){
 int num=0;
 num=selectNum(p, curi);
 if(num==0){
  printf("Canceled!\n");
  return;
 }

 getchar();
 printf("Enter new product's name : ");
 gets(p[num]->name);
 printf("Enter new product's weight : ");
 scanf("%d", &p[num]->weight);
 printf("Enter new product's cost : ");
 scanf("%d", &p[num]->cost);
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
