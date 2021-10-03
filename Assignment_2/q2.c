#include<stdio.h>
#include<stdlib.h>

struct node{
 char name[20];
 int rollno, year;
 char prog[30];
 struct node *next;
};

struct node *head = NULL;
void show(){


if(head==NULL){
    printf("empty queue");

}

struct node *temp = head;
while(temp!=NULL){
    printf("\nname = %s \nroll no. = %d \nyear of joining = %d \nProgram = %s\n" , temp->name , temp->rollno , temp-> year ,temp -> prog );
    temp = temp->next;
}

}

void insert(){

    struct node *link = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter name :");
    scanf("%s" , link->name);
    printf("Enter roll number :");
    scanf("%d" , &link->rollno);
    printf("Enter year of joining:");
    scanf("%d" , &link->year);
    printf("Enter name of programme :");
    scanf("%s" , link->prog);
    link->next=head;
    head=link;
    printf("Node inserted at the brginning successfuly");

}
 
void delete(){
    
    if(head==NULL){
        printf("cant delete from empty list :(");
        return;
    }
    struct node *deleted = head;
    head=head->next;
    free(deleted);
    printf("Node deleted Successfully")
    
}

void main(){
    
    delete();
    insert();
    delete();
   // delete();
}