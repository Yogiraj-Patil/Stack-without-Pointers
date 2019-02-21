//dynamic memory allocation collection type
//always dynamic collection
//no linear data structure means storing of element is not on side by side memory location
#include<stdio.h>
#include<stdlib.h>
int length(void);

int main()
{   int loc;
    int ch;
    while(1){
    printf("\n\nSingle Linked List Operations\n");
    printf("1. Append\n");
    printf("2. Add at begining\n");
    printf("3. Add After\n");
    printf("4. length\n");
    printf("5. Display\n");
    printf("6. Delete\n");
    printf("7. Swap\n");
    printf("8. Reverse List\n");
    printf("9. Quit\n\n");
    printf("Enter Your Choice:\n"); scanf("%d",&ch);
    switch(ch)
    {
        default:  printf("Please Enter a Valid Choice\n\n");
        break;
        case 1: append();
        break;
        case 2: addatbegin();
        break;
        case 3: printf("\nEnter The Location: \n"); scanf("%d",&loc);
                addafter(&loc);
        break;
        case 4: printf("Length is: %d \n",lenght());
        break;
        case 5: traverse();
        break;
        case 6: printf("\nEnter The Location: "); scanf("%d",&loc);
                deletefunction(&loc);
        break;
        case 8:  reverse();
        break;
        case 7: printf("\nEnter the location: "); scanf("%d",&ch);
                swap(ch);
        break;
        case 9: exit(1);
        break;
    }
    }
}


struct node{
int data;
struct node* link;

};
struct node* root = NULL;


void reverse(){

struct node *p,*q;
int i,j,k,temp;
j=lenght() -1;
i=0; p=q=root;
while(i<j){
    k=0;
    while(k<j){
        q = q->link;
        k++;
    }
    temp = q->data;
    q->data = p->data;
    p->data = temp;

    i++;
    j--;
    p = p->link;
    q=root;
}

}


void swap(int loc)
{
    if(lenght() < loc){
        printf("\nPlease Enter Valid location\n");
    }else{
        struct node* temp; struct node* q; struct node* r;
        temp=root;
        int i=1;
        while(i<loc-1)
        {
            temp = temp->link;
            i++;
        }
        //q = (struct node*)malloc(sizeof(struct node));
        q = temp->link;
        r = q->link;

        q->link = r->link;
        r->link = q;
        temp->link = r;

        printf("\nSwapping successfully\n");
        traverse();

    }
}




void deletefunction(int* loc){
   struct node* temp;
   int data;
   if(*loc > lenght() || *loc == 0){
    printf("\nlocation is Invalid\n");
    return;
   }
   else if(*loc == 1){
    temp = root;
    root = temp->link;
    temp->link = NULL;
    data = temp->data;
    free(temp);
   }else
   {
    temp = root;
    int i = 1;
    while(i < *loc-1){
        i++;
        temp = temp->link;
    }
    struct node *q;
    q=temp->link;
    temp->link = q->link;
    q->link = NULL;
    data = q->data;
    free(q);
   }
   printf("\n Node At Location %d is successfully deleted and Item is %d",*loc,data);
}


void addatbegin()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to Node:\n");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root == NULL)
    {
        root = temp;
        printf("New Root Created at the begining");
    }
    else{
        temp->link = root;
        root = temp;
        printf("Node added at begining");
    }
}


void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data:\n");scanf("%d",&temp->data); //here we took & cause in structure it not a pointer declaration
    temp->link = NULL;//here we dont take & because in mainstructure we define as a pointer
    if(root == NULL){
        root = temp;
        printf("New Node Enter at the begining");
    }else
    {
        struct node* p;
        p=root;
         while(p->link != NULL)
         {
            p = p->link;
         }
         p->link = temp;
         printf("New Node Successfully Appended");
    }
}

int lenght()
{
    int count = 0;

    struct node* temp =root;
    if(root == NULL)
    {
        return 0;
    }
    while(temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}


void traverse(){

if(root == NULL)
{
    printf("Linked list is Empty");
}
else{
    struct node* temp = root;
    printf("Linked List Data is below \n");
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->link;
    }
    printf("NULL");
    printf("\n\n");
}
}

int addafter(int *loc){
    if(*loc > lenght() || *loc == 0)
    {
        printf("\nPlease Enter Valid Location");
    }else{
        int i = 1;
        struct node* p = root;
        while(i<*loc)
        {
            p = p->link;
            i++;
        }
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data: \n");scanf("%d",&temp->data);
        temp->link = p->link;
        p->link = temp;
        printf("New Node placed Successfully");

    }
}

