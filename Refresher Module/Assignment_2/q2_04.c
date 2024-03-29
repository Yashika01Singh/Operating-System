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
    printf("Empty queue\n");
    return;

    }

struct node *temp = head;
while(temp!=NULL){
    printf("\nName = %s \nRoll no. = %d \nYear of Joining = %d \nProgram = %s\n" , temp->name , temp->rollno , temp-> year ,temp -> prog );
    temp = temp->next;
    }

}



void push(){
//inserts at end of queue
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
void pop(){
    //insert from front of queue
    if(head==NULL){
        printf("Cant delete from empty list :(\n");
        return;
    }
    struct node *temp = head->next;
    if(tail == temp){
        tail=NULL;
        }
    else {
        head->next->prev = NULL;
    }
    free(head);
    head=temp;
    
    
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
        printf("\nEnter operation \n1.Enqueue \n2.Dequeue \n3.Show \n4.Find\n5.quit\n");
        scanf("%d" , &query);
        if(query >5){
            printf("Invalid choice try again");
            continue;
        }
        if(query == 5){
            break;
        }
        if(query == 1){
            push();

        }
        if(query == 2){
           pop();
           printf("Node popped from queue\n");
        }
        if(query == 3){
            show();
            
        }
        if(query==4){
            find();
        }
    }
    //freeing space 
    while(head!=NULL){
        pop();
    }
    
    
}