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
    //insert node at begining of list
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
    //delete node from begining of list
    if(head==NULL){
        printf("cant delete from empty list :(\n");
        return;
    }
    struct node *temp = head->next;
    
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
        printf("\nEnter operation \n1.Insert \n2.Delete \n3.Show\n4.Find\n5.quit\n");
        //function to send to corresponding functions
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
        if(query==4){
            find();
        }
        
    }

    //deallocating memory
    while(head!=NULL){
        delete();
    }
    
}