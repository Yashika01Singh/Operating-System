#include <stdio.h>
#include <stdlib.h>


int main(){
int *p[6];
int length[6];
int size;
for(int i=0 ; i<6 ; i++){
    printf("Enter number of culumns in %d  : " , i);
   
    scanf("%d",&size);
    length[i]=size;
    p[i] = (int*)malloc(size*sizeof(int));
    for(int j=0 ; j< size ; j++){
        *(p[i]+j)=rand() % 11;        
    }
}

for(int i=0; i<6 ; i++){
    for(int j=0;j<length[i];j++){
        printf("%d ",*(p[i]+j));
    }
    printf("\n");
}
}