#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{ 
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int addProduct(Product *p);
void readProduct(Product p);
void loopRead(Product *p[], int curi);
void updateProduct(Product *p[], curi);
void deleteProduct(Product *p[], curi);
int selectNum(Product *p[], int curi);
