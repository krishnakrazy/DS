#include<stdio.h>
#include<stdli.h>
#include<string.h>


struct LinkedList{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList LL;
LL *root;

int createNode()