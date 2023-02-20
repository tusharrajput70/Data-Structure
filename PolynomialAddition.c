#include<stdio.h>
#include<stdlib.h>
struct node{
    int coefficient;
    int degree;
    struct node *next;
};

struct node *start;
struct node *tail;
void create(int coefficient,int degree){
    struct node *newnode=malloc(sizeof(struct node));
    if(start==NULL){
        tail=start=newnode;
        newnode->coefficient=coefficient;
        newnode->degree=degree;
        newnode->next=NULL;
    return;
    }
    tail->next=newnode;
    newnode->coefficient=coefficient;
    newnode->degree=degree;
    newnode->next=NULL;
    tail=newnode;
}



struct node *start2;
struct node *tail2;
void create2(int coefficient,int degree){
    struct node *newnew=malloc(sizeof(struct node));
    if(start2==NULL){
        tail2=start2=newnew;
        newnew->coefficient=coefficient;
        newnew->degree=degree;
        newnew->next=NULL;
        return;
    }
    tail2->next=newnew;
    newnew->coefficient=coefficient;
    newnew->degree=degree;
    newnew->next=NULL;
    tail2=newnew;
}

struct node *start3;
struct node *tail3;

void sum(struct node *start, struct node *start2){
    for(struct node *i=start;i!=NULL;i=i->next){
        struct node *temp=malloc(sizeof(struct node));
        temp->coefficient=0;
         for(struct node *j=start2;j!=NULL;j=j->next){
            if(j->degree==i->degree){
                temp->coefficient+=i->coefficient+j->coefficient;  
            }
        }
        temp->degree=i->degree;
        if(start3==NULL){
            tail3=start3=temp;
        }else{
            tail3->next=temp;
            tail3=temp;
        }
        temp->next=NULL;
    }
}

void print(struct node* start){
    struct node *temp=start;
    while(temp!=NULL){
        if(temp->coefficient>0){
            printf("+%dx^%d",temp->coefficient,temp->degree);
        }else{
            printf("-%d x^%d",temp->coefficient,temp->degree); 
        }
        temp=temp->next;
    }
    printf("\n");
}
void main(){
    int n=0;
    printf("Enter 1st polynomial\n");
    while(n!=2){
        printf("To enter new element press 1.\nTo end press 2.\n");
        scanf("%d",&n);
        switch(n){
            case(1):{
                int coefficient;
                int degree;
                printf("Enter coeffient with sign\n");
                scanf("%d",&coefficient);
                printf("Enter degree\n");
                scanf("%d",&degree);
                create(coefficient,degree);
                break;
            }
        }
    }

    int m=0;
    printf("Enter 2nd polynomial\n");
    while(m!=2){
        printf("To enter new element press 1.\nTo end press 2.\n");
        scanf("%d",&m);
        switch(m){
            case(1):{
                int coefficient;
                int degree;
                printf("Enter coeffient with sign\n");
                scanf("%d",&coefficient);
                printf("Enter degree\n");
                scanf("%d",&degree);
                create2(coefficient,degree);
                break;
            }
        }
    }
    printf("Polynomial 1:");
    print(start);
    printf("\n");
    printf("Polynomial 2:");
    print(start2);
    printf("\n");
    sum(start,start2);
    printf("Sum Of Polynomials = ");
    print(start3);
}