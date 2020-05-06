#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{ 
    char name[20];
    int weight;
    int cost;
    int count;
} Product;

int addProduct(Product *p);
void readProduct(Product p);
void loopRead(Product *p[], int curi);
void updateProduct(Product *p[],int curi);
void deleteProduct(Product *p[],int curi);
int selectNum(Product *p[], int curi);
