#include <stdio.h>

int main(){

printf("Enter size of string : ");
int size;
scanf("%d",&size);
char st[size];

scanf("%s",st);
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