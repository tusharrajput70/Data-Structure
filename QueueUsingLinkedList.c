#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
static int size = 0;
void enqueue(int item)
{
    size++;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = item;
    if (head == NULL && tail == NULL)
    {
        head = tail = temp;
        tail->next = NULL;
        return;
    }
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}
int dequeue()
{
   if (head == NULL)
    {
        printf("Linked list is empty\n");
        return -1;
    }
    size--;
    int val = head->data;
    head = head->next;
    return val;
}
void peek(){
    if(head==NULL){
        printf("Stack underFlow\n");
        return;
    }
    printf("Element at top is: %d\n",head->data);
}
void reverse()
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void display(){
    if(head==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node *temp=head;
    printf("Stack looks like:\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main(){
    int n;
    printf("Tushar rajput 2100320130183\n");
    while(n!=5){
        printf("Press 1 for enqueue.\nPress 2 for dequeue.\nPress 3 for peek.\nPress 4 for display.\nPress 5 for exit.\n");
        scanf("%d",&n);
        switch(n){
            case(1):{int m;
            printf("Enter data\n");
            scanf("%d",&m);
            enqueue(m);
            }
            break;
            case(2):printf("dequeue element is: %d\n",dequeue());
            break;
            case(3):peek();
            break;
            case(4):display();
            break;
            case(5):
            break;
        }
    }
}

