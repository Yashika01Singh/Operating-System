#include<stdio.h>
void addition(int a,int b){
    printf("The result %d + %d is : %d " , a,b,a+b);
}
void subtraction(int a,int b){
    printf("The result %d - %d is : %d " , a,b,a-b);
}
void division (int a,int b){
    float answer;
    if(b==0){
        printf("Can't divide by zero");
        return;
    }
    answer = a/(float)b;
    printf("The result %d / %d is : %.2f " , a,b,answer);
}
void multiplication(int a,int b){
    long answer = a*b;
    printf("The result %d + %d is : %ld " , a,b,answer);
}
void exponentiation(int a,int b){
 if(b<0){
     printf("Please enter a positive number for power");
        return;
 }
 long answer=1;
 for(int i =1 ; i<=b ;i++){
     answer=answer*a;
     }
printf("The result %d ^ %d is : %ld " , a,b,answer);
}

int main(){

void (*ptr[])(int,int) = {addition,subtraction,division,multiplication,exponentiation};
int a,b;
printf("Enter two integers : \n");

scanf("%d" , &a);
scanf("%d" ,&b);
printf("Enter choice for the following queries (1 - 5) :\n");
printf("1.Addition \n2.Subtraction \n3.division \n4.Multiplication \n5.Exponentiation \n");
int choice;
scanf("%d" , &choice);
choice--;
//printf("%d" , choice);
if(choice>4){
    printf("Wrong choice\n");
    return(1);
}

(*ptr[choice])(a,b);

}
