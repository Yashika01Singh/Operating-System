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
    printf("empty queue\n");

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
    printf("Node inserted at the brginning successfuly\n");

}
 
void delete(){
    
    if(head==NULL){
        printf("cant delete from empty list :(\n");
        return;
    }
    struct node *temp = head->next;
    
    free(head);
    head=temp;
    
    
}

int main(){
    int query;
    while(1){
        printf("\nEnter operation 1.Insert \n2.Delete \n3.Show\n5.quit\n");
   
        scanf("%d" , &query);
        if(query >5){
            printf("Invalid choice try again");
            continue;
        }
        if(query == 5){
            break;
        }
        if(query == 1){
            insert();
        }
        if(query == 2){
            delete();
        }
        if(query == 3){
            show();
        }
        
    }

    //deallocating memory
    while(head!=NULL){
        delete();
    }
    
}