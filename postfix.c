// Write a menu driven program to convert a given infix expression to its postfix form and evaluate it.
#include <stdio.h>
#include <ctype.h>

char stack[100];
char postfix[100], m=-1;
int top = -1;

void convert()
{
    void push(char x)
    {
        stack[++top] = x;
    }

    char pop()
    {
        if(top == -1)
            return -1;
        else
            return stack[top--];
    }

    int priority(char x)
    {
        if(x == '(')
            return 0;
        if(x == '+' || x == '-')
            return 1;
        if(x == '*' || x == '/')
            return 2;
        return 0;
    }

    void output()
    {
        char *e, x;
        e = stack;
    
        while(*e != '\0')
        {
            if(isalnum(*e))
                printf("%c ",*e);
            else if(*e == '(')
                push(*e);
            else if(*e == ')')
            {
                while((x = pop()) != '(')
                    printf("%c ", x);
                    postfix[++m]=x;
            }
            else
            {
                while(priority(stack[top]) >= priority(*e))
                    printf("%c ",pop());
                    postfix[++m]=x;
                push(*e);
            }
            e++;
        }
    
        while(top != -1)
        {
            char t=pop();
            printf("%c ", t);
            postfix[++m]=t;
        }
        printf("\n");
    }
    output();
}

void evaluate()
{
    int i, val, A, B;
    char *p, ch;
    int arr[100], toparr=-1;
    p=postfix;
    
    void push(int num)
    {
        if(toparr==((sizeof(arr)/sizeof(arr[0]))-1))
        {
            printf("Stack Overflow.\n");
        }
        else
        {
            toparr++;
            arr[toparr]=num;
        }
    }

    int pop()
    {
        if(toparr==-1)
        {
            printf("Stack Underflow.\n");
        }
        else
        {
            int item=arr[toparr];
            toparr--;
            return item;
        }
    }

    for (i = 0; i<((sizeof(postfix)/sizeof(postfix[0]))-1); i++) 
    {
        ch = postfix[i];
        if (isdigit(ch)) 
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        {
            A = pop();
            B = pop();

            switch (ch) 
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }
            push(val);
        }
    }
    printf(" \nResult of expression evaluation : %d \n", pop());
}

void main()
{
    int ch;
    printf("Enter an infix expression.\n");
    scanf("%s", stack);
    int a=0;
    while(a==0)
    {
        printf("1. Convert expression to posfix\n2. Evaluate the postfix expression\n3. Exit\n");
        printf("Enter a choice:\n");
        scanf("%i", &ch);
        if(ch==1)
        {
            convert();
        }
        else if(ch==2)
        {
            evaluate();
        }
        else
        {
            printf("Exiting the program\n");
            a++;
        }
    }
}

