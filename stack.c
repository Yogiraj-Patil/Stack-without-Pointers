//the stack is a abstract data types or set of rules
//the rule are last in first out
//e.g cd stand
/*Static Implementation using static array*/
#include<stdio.h>
#define CAPACITY 5 //preprocessor micro
int top = -1;
int stack[CAPACITY];

int push(int);
int isFull(void);
void pop(void);
int isEmpty(void);
void peek(void);
void traverse(void);



int main(){
int choice;
int a = 0;
while(a == 0){
printf("\n\n1. Push\n2. Pop\n3. trvrese\n4. Peek\n5. Exit\n");
scanf("%d",&choice);
int x;
switch(choice){
    case 1:
        printf("Enter Element ");
        scanf("%d",&x);
        push(x);
    break;
    case 2:
        pop();
    break;
    case 3:
        traverse();
    break;
    case 4:
        peek();
    break;
    case 5:
        a=1;
    break;
    default:
        printf("\nPlease Enter Valid Choice");
    break;
}
}
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack is Underflow");
        return;
    }
    printf("\nTop of the stack is %d",stack[top]);
}


void traverse()
{
    if(isEmpty())
    {
        printf("\n\nStack is Empty for Traversal");
    }
    else{
        int i;
        printf("\n Stack Element is Below");
        for(i=0;i<=top;i++){
            printf("\n%d",stack[i]);
        }
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("\n\nStack is Underflow");
    }
    else{
        printf("Element %d remove from stack",stack[top--]);
        //top--;
    }
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}


int push(int x)
{
    if(isFull())
    {
        printf("\nStack is Overflow");
    }
    else{
        top++;
        stack[top] = x;
        printf("\nElement %d added",x);
    }

}

int isFull(){
    if(top == CAPACITY-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
