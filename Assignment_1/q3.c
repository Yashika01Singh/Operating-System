#include <stdio.h>

int main(){


printf("Enter size for first variable: \n");
int size;
scanf("%d",&size);

int arr1[size];
printf("Enter elements for first array: \n");
for(int i=0 ; i<size ; i++){
    scanf("%d",&arr1[i]);
}

int arr2[size];
printf("Enter elements for first array: \n");
for(int i=0 ; i<size ; i++){
    scanf("%d",&arr2[i]);
}
int temp[size];
for(int i=0 ; i<size ; i++){
    temp[i]=arr1[i];
    arr1[i]=arr2[i];
    arr2[i]=temp[i];
}
printf("Variable 1 : ");
for(int i=0 ; i<size ;i++){
   printf("%d ",arr1[i]); 
}
printf("\n");
printf("Variable 2 : ");
for(int i=0 ; i<size ;i++){
   printf("%d ",arr2[i]); 
}

}