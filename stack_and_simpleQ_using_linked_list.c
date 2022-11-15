#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *front = NULL, *rear = NULL;

bool stack_empty()
{
    return top == NULL;
}
void stack_push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (top)
        newNode->next = top;
    top = newNode;
}

int stack_pop()
{
    if (stack_empty())
        return -1;
    int del = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);

    return del;
}


void display()
{
    if (stack_empty())
        return;
    for (struct Node *ptr = top; ptr; ptr = ptr->next)
        printf("%d ", ptr->data);
}

bool qEmpty()
{
    return front == NULL && rear == NULL;
}



void enQueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}

int deQueue()
{
    if (qEmpty())
        return -1;

    int deleted = front->data;
    struct Node *temp = front;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;

    free(temp);
    return deleted;
}



void qdisplay()
{
    if (qEmpty())
    {
        printf("Empty\n");
        return;
    }
    for (struct Node *curr = front; curr; curr = curr->next)
        printf("%d ", curr->data);
}


void main()
{
int ch1, x=0;
while(x==0)
{
printf("1. Linked stack\n2. Linked queue\n3. Exit\n");
printf("Enter a choice:\n");
scanf("%i"
, &ch1);
if(ch1==1)
{
int s=0, ch2;
while(s==0)
{
printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
printf("Enter a choice:\n");
scanf("%i"
, &ch2);
if(ch2==1)
{
int element;
printf("Enter an element:\n");
scanf("%i", &element);
stack_push(element);
}
else if(ch2==2)
{
printf("The element deleted is: %i\n", stack_pop());
}
else if(ch2==3)
{
display();
}
else
{
s++;
}
}
}
else if(ch1==2)
{
int q=0, ch2;
while(q==0)
{
printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
printf("Enter a choice:\n");
scanf("%i", &ch2);
if(ch2==1)
{
int element;
printf("Enter an element:\n");
scanf("%i", &element);
enQueue(element);
}
else if(ch2==2)
{
deQueue();
}
else if(ch2==3)
{
qdisplay();
}
else
{
q++;
}
}
}
else
{
printf("Exiting the program\n");
x++;
}
}
}