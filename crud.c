int addProduct(Producc *p){
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
 printf(" %-10s %-5d %d\n");
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
