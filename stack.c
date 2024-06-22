/*
 * Program to create a stack, support push and pop operations
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 10

int top(void);
int isEmpty(void);
int isFull(void);
int sizeOfStack(void);
void push(int data);
int pop(void);
int maxSize(void);
void display(void);

struct stack{
    int size;
    int data[MAX_LEN];
    int (*top)(void);
    int (*isEmpty)(void);
    void (*push)(int data);
    int  (*pop)(void);
    int (*maxSize)(void);
    int (*sizeOfStack)(void);
    int (*isFull)(void);
    void (*display)(void);
}stk = {-1,{0}, top, isEmpty, push, pop, maxSize, sizeOfStack, isFull, display};


int top(void){
    return stk.size;
}

int isEmpty(void){
    if ( stk.size == -1)
       return 1;
    else 
       return 0;
}


int isFull(void){
    return( stk.size == MAX_LEN-1);
}

int sizeOfStack(void){
    return (stk.size + 1);
}

void push(int data){
    if ( stk.isFull()){
         printf("\n Stack is full, can't push anymore elements...\n");
         return;
    }
  
    stk.size++;
    stk.data[stk.size] = data;
}

int pop(void){
    int tmp;
    if ( stk.isEmpty()){
        printf("\n Stack is Empty, can't pop anymore items...\n");
        return -1;
    }
    printf("\n Popping %d from stack", stk.data[stk.size]);
    tmp = stk.data[stk.size];
    stk.data[stk.size] = 0;
    stk.size--;
    return tmp;
}

int maxSize(void){
    return MAX_LEN;
}

void display(void)
{
    int i = 0;
    if ( stk.isEmpty()){
        printf("\n STACK IS EMPTY... \n");
        return;
    }
    i = stk.top();
    while ( i > -1)
    {
        printf(" %d ", stk.data[i]);
        i--;
    }
    return;
}

int main(void)
{
    int data;
    int ch;

    do{
        printf("\n Max size of Stack is 10 \n Choose operations: \n 1. PUSH \n 2. POP \n 3. DISPLAY \n 4. EXIT");
        ch=getchar();
        switch(ch){
            case '1':
                   printf("\n Enter value to push \n");
                   scanf("%d", &data); 
                   stk.push(data);
                   break;
            case '2': 
                   data = stk.pop();
                   printf("\n poppped %d ", data);
                   break;
            case '3':
                   stk.display();
                   break;
        }

    }while(ch != '4');
    while( stk.top() > -1)
    {
        stk.pop();
    }
    printf("\n ===========\n");
    return 0;
}