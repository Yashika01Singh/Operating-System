#include <stdio.h>

int main(){


char st[1000];
int i;
  
printf("Enter the String: ");
scanf("%s", st);
int size;
for (size = 0; st[size] != '\0'; ++size);
//printf("%d" , size);
char newst[size];
newst[size]=st[size];
for(int i=size-1 ; i>-1 ; i--){
    newst[size-i]=st[i]; 
}
for(int i=0 ; i<=size ; i++){
  printf("%c",newst[i]);  
}
printf("\n");

}