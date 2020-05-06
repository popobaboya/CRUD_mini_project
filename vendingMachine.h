#include <stdio.h>
#include <string.h>

typedef int bool;
enum{false, true};

typedef struct _Coin{
	int baekwon;
	int o_baekwon;
	int total_won;
} Coin;

int listConsumer();
int listAdministrator();
int coinRefill(Coin *coin);
int changePassword(char* password);