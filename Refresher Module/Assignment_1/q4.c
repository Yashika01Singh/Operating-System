#include <stdio.h>

int main(){
char st[1000];

printf("Enter the String: ");
scanf("%s", st);
int size;
for (size = 0; st[size] != '\0'; ++size);
//printf("%d" , size);
char newst[size];
// newst stores the reversed string
newst[size]=st[size];
//storing reversed st in new string newst 
for(int i=size-1 ; i>-1 ; i--){
    newst[size-i]=st[i]; 
}

//printing newst : reversed string
for(int i=0 ; i<=size ; i++){
  printf("%c",newst[i]);  
}
printf("\n");

}