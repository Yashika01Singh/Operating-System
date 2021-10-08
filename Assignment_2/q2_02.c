#include<stdio.h>
#include<stdlib.h>

struct node{
 char name[20];
 int rollno, year;
 char prog[30];
 struct node *next , *prev;
};
struct node* new (){
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter name :");
    scanf("%s" , new_node->name);
    printf("Enter roll number :");
    scanf("%d" , &new_node->rollno);
    printf("Enter year of joining:");
    scanf("%d" , &new_node->year);
    printf("Enter name of programme :");
    scanf("%s" , new_node->prog);
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;
}
struct node *head = NULL;
struct node *tail = NULL;
void show(){


if(head==NULL){
    printf("Empty list\n");
    return;

    }

struct node *temp = head;
while(temp!=NULL){
    printf("\nName = %s \nRoll no. = %d \nYear of Joining = %d \nProgram = %s\n" , temp->name , temp->rollno , temp-> year ,temp -> prog );
    temp = temp->next;
    }

}

void showrev(){

    if(tail==NULL){

        printf("Empty list\n");
        return;
    }
    struct node *temp = tail;
    while(temp!=NULL){
    printf("\nName = %s \nRoll no. = %d \nYear of Joining = %d \nProgram = %s\n" , temp->name , temp->rollno , temp-> year ,temp -> prog );
    temp = temp->prev;
    }


}

void insertfirst(){

    struct node *link = new();
    if(tail==NULL){
        tail=link;
    }
    else {
        head->prev =link;
    }
    link->next=head;
    head=link;
    printf("Node inserted at the beginning successfuly\n");

}
void insertlast(){

struct node *link = new();
if(tail==NULL){
    head=link;
    }
else {
    tail->next = link;
    }
link->prev = tail;
tail=link;
printf("Node inserted at the last successfuly\n");

}
void deletefirst(){
    
    if(head==NULL){
        printf("Cant delete from empty list :(\n");
        return;
    }
    struct node *temp = head->next;
    if(tail ==head){
        tail=NULL;
        }
    else {
        head->next->prev = NULL;
    }
    free(head);
    head=temp;
    
    
}
void deletelast(){
    if(head==NULL){
        printf("--Cant delete from empty list :(\n");
        return;
    }
    struct node *temp = tail->prev;
    if(head == temp){
        head=NULL;
        }
    else {
        tail->prev->next = NULL;
    }
    free(tail);
    tail=temp;
}
void find(){
    struct node *temp =head;
    printf("What roll number you want to search in records ");
    int roll;
    scanf("%d" ,&roll);
    char a='0';
    while(temp!=NULL){

        if(temp->rollno==roll){
            a='1';
            break;
        }
        temp=temp->next;

    }
    if(a=='1'){
        printf("Given roll no is present in the records");
    }
    else{
        printf("Given roll no is not present in the records");
    }

}

int main(){

    int query;
    
    while(1){
        
        printf("\nEnter operation \n1.Insert at beg \n2.Insert at last \n3.Delete from beg\n");
        printf("4.Delete from last\n5.show\n6.show in reverse\n7.find\n8.exit\n");
        scanf("%d" , &query);
        if(query >8){
            printf("Invalid choice try again");
            continue;
        }
        if(query == 8){
            break;
        }
        if(query == 1){
            insertfirst();
        }
        if(query == 2){
            insertlast();
        }
        if(query == 3){
            deletefirst();
        }
        if(query == 4){
            deletelast();
        }
        if(query==5){
            show();
        }
        if(query==6){
            showrev();
        }
        if(query==7){
            find();
        }
        
    }
    //deallocating memory
    while(head!=NULL){
       
        deletefirst();
        
    }
    
    
}