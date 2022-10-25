// Write a menu driven program to implement a stack using arrays and perform the given
//operations: Push elements to the stack. Pop elements from the stack. Display the contents of
//stack after each operation.
#include <stdio.h>
int n, arr[100], top=-1;
void push(int arr[100])
{
int num;
if(top==n-1)
{
printf("Stack full! Cannot enter any more elements.\n");
}
else
{
printf("Enter an element:\n");
scanf("%i"
, &num);
top++;
arr[top]=num;
}
}
void pop(int arr[100])
{
if(top==-1)
{
printf("Stack is empty! Cannot pop any more elements.\n");
}
else
{
int item=arr[top];
printf("%i has been deleted from the stack\n"
, item);
top--;
}
}
void display(int arr[100])
{
if(top==-1)
{
printf("[]\n");
}
else
{
for(int t=top; t>=0; t--)
{
printf("%i\t"
, arr[t]);
}
printf("\n");
}
}
void main()
{
printf("Enter the size of the stack:\n");
scanf("%i"
, &n);
int ch;
int m=0;
while(m==0)
{
printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
printf("Enter a choice:\n");
scanf("%i"
, &ch);
if(ch==1)
{
push(arr);
}
else if(ch==2)
{
pop(arr);
}
else if(ch==3)
{
display(arr);
}
else
{
printf("Exiting the program");
m++;
}
}
}