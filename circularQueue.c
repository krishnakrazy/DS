/*
 * Program to implement queue, and support its operations enqueue and dequeue
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 5

void initQ(void);
void enq(int data);
int deq(void);
void display(void);
void display(void);




struct queue{
    int data[MAX_LEN];
    volatile int front;
    volatile int rear;
    int circular;
    volatile int is_empty;
    volatile int is_full;
    void (*initQ)(void);
    void (*enq)(int);
    int (*deq)(void);
    void (*display)(void);
    //int (*isEmpty)(void);
    //int (*isFull)(void);
}qu = {{0}, -1, -1, 0, 1, 0, initQ, enq, deq, display};


void initQ(void)
{
    qu.front = -1;
    qu.rear = -1;
    qu.data[0] = -1;
}

void enq(int data)
{
     printf("\n Front is at %d \n", qu.front);
    if ( ( qu.rear == MAX_LEN - 1 ) &&   // Q is full, to check regular boundary condition
         ( qu.front == 0)                 // Q is full, no elements are deleted, so Q is actually Full
       )
    {
        printf("\n Queue is Full\n");
        qu.is_full = 1;
        qu.is_empty = 0;
        return;
    }
    if ( qu.is_empty )      // Q is Empty, add first element into Q
    {
        printf("\n Queue is Empty, adding first element \n");
        qu.initQ();
        qu.is_empty = 0;
        qu.front = 0;
    }
    if (qu.circular)
    {
        if (qu.rear == qu.front - 1)   // rear and front are adjacent, which means Queue is Full
        {
            printf("\n Circular Queue is Full \n");
            return;
        }
    }
    if ((qu.front != 0) &&
         (qu.rear == MAX_LEN -1)
       )                          // restting rear to initial index, only if elements are deleted from front of Q and rear has reached boundary
    {
        qu.rear = -1;
        qu.circular = 1;
    }   //special condition for Circular Q
    // add element
    qu.rear++;
    qu.data[qu.rear] = data;
    printf("\n %d added to queue at %d", qu.data[qu.rear], qu.rear);
    return;
}

int deq(void)
{
    if ( qu.is_empty && !qu.circular)
    {
        printf("\n Queue is Empty...\n Nothing to Delete \n");
        qu.initQ();
        return 0;
    }
    int tmp;
    tmp = qu.data[qu.front];
    printf("\n deleting %d from QUEUE \n", tmp);
    qu.data[qu.front] = 0;
    qu.front++;
    if ( qu.circular)
    {
        if (qu.front == MAX_LEN - 1)
        {
            qu.front = 0;
            qu.circular = 0;
        }
    }    
    else if ( !qu.circular )
    {
        if (qu.front > qu.rear)
        {
            qu.is_empty = 1;
            qu.is_full = 0;
        }
    }
    return tmp;
}

void display(void)
{
   int index;
   if ( !qu.circular)
   {
       if ( !qu.is_empty )
       {
           for ( index = qu.front; index <= qu.rear; index++)
           printf("  %d  ", qu.data[index]);
       }
       else  
           printf("\n Queue is Empty\n");
       return;
   }
   else if ( qu.circular )
   {
       for ( index = qu.front; index <= MAX_LEN -1; index++)
              printf("  %d  ", qu.data[index]);
       for ( index = 0; index < qu.front; index++)
              printf("  %d  ", qu.data[index]);
   }
}
inline int isEmpty(void)
{
    if ( ( qu.front > qu.rear ) || 
         (( qu.front == -1 ) && (qu.rear == -1))
       )
          return 1;
    else
         return 0;
        
}

inline int isFull(void)
{
    if ( qu.rear == MAX_LEN - 1 )
       return 1;
    else 
       return 0;

}


int main(void)
{
    int data;
    int ch;

    do{
        printf("\n Max size of Queue is %d \n Choose operations: \n 1. ADD \t 2. DELETE \t 3. DISPLAY \t 4. EXIT \n", MAX_LEN);
        ch=getchar();
        switch(ch){
            case '1':
                   printf("\n Enter value to Enq \n");
                   scanf("%d", &data); 
                   qu.enq(data);
                   break;
            case '2': 
                   data = qu.deq();
                   printf("\n poppped %d ", data);
                   break;
            case '3':
                   qu.display();
                   break;
        }

    }while(ch != '4');


    while( !qu.is_empty )
    {
        data = qu.deq();
        printf( "   %d   ", data);
    }
    printf("\n ===========\n");
    return 0;
}