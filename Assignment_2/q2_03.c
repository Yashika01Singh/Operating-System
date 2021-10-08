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

void push(){

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
    printf("Node pushed in Stack\n");

}
 
void pop(){
    
    if(head==NULL){
        printf("Cant pop from empty Stack :Underflow :(\n");
        return;
    }
    struct node *temp = head->next;
    
    free(head);
    head=temp;
    
    
}

int main(){

    int query;
    
    while(1){
        printf("\nEnter operation \n1.Push \n2.Pop \n3.Show \n4.quit\n");
        scanf("%d" , &query);
        if(query >4){
            printf("Invalid choice try again");
            continue;
        }
        if(query == 4){
            break;
        }
        if(query == 1){
            push();

        }
        if(query == 2){
           pop();
        
        }
        if(query == 3){
            show();
            
        }

    }
    
    
    printf("\nFreeing space from memory...\n");
    while(head!=NULL){
        pop();
        
    }
    
}