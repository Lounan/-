#ifndef _MYPHONEBOOK_H_
#define _MYPHONEBOOK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h> 
typedef struct info
{
	char name[20];
	char phone_num[12];

}INF;

typedef struct node
{
	char name[20];
	char phone_num[12];
	struct node * next;

}INODE;

INODE *h;//Í·½áµã

void empty_head()
{
	h = (INODE *)malloc(sizeof(INODE));
	h->next = NULL;
}
int amount = 0;

void show();


#endif