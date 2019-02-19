//Single Link List using stack or vice versa
#include<stdio.h>
struct node{
int data;
struct node* link;
};
struct node* top = NULL;

int main()
{
 while(1)
 {
    int a;
    printf("\n\n1. Push\n2. Pop\n3. Travrsal\n4. Length\n5. Exit");
    printf("\n\tEnter your Choice: "); scanf("%d",&a);
    switch(a){
        default : printf("\nPlease Enter Valid Choice");
        break;
        case 1:
                printf("Enter the Element to Push:  ");scanf("%d",&a);
                push(a);
        break;
        case 2:
                pop();
        break;
        case 3: travels();
        break;
        case 4: printf("\nLength of stack is %d \n",length());
        break;
        case 5: exit(1);
        break;
    }
 }
}

void push(int data)
{
    struct node* temp;
    temp =(struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = top;
    top = temp;
}

void pop(){
    if(top == NULL)
    {
        printf("\nThe Stack of Linked list is Empty");
    }else{
        struct node* temp;
        temp = top;
        top = top->link;
        temp->link = NULL;
        printf("\n%d has been Poped from stack of linked list",temp->data);
        free(temp);
    }
}

void travels()
{
    if(length() == 0)
    {
        return;
    }else{
        struct node* temp;
        temp=top;
        while(temp != NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("NULL");
    }
}

int length(){
    if(top == NULL)
    {    printf("\nThe Stack of Linked list is Empty");
        return 0;
    }else{
        struct node* temp;
        temp = top;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp->link;
        }

        return count;
    }
}
