#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a , const void *b){
    const unsigned int *x = a , *y =b;
    if(*x > *y){
        return 1;
    }
    return 0;
}

void Binary_Search (unsigned int array[] ,long size, unsigned int element ){
    long left= 0;
    long right = size-1;
    long middle;
    while(left<=right){
        middle = (left+right)/2 ;
        if(array[middle]==element){
            printf("%u is present at position %ld in the sorted array "  ,element , middle+1 );
            return;
        }

        if(array[middle]<=element){
            left=middle+1;
            continue;
        }

        if(array[middle]>=element){
            right=middle-1;
            continue;
        }
    }
    
    if(left>right){
        printf("Element is not present in the array :(");
        return;
    }
    printf("something happened that should never happen");
}


int main(){
long size ;
printf("Enter number of elements \n");
scanf("%ld" , &size);
unsigned int array[size];
printf("Enter elements space seperated : ");
for(int i=0 ; i<size ; i++){
    scanf("%u" , &array[i]);
}
qsort(array , size , sizeof(unsigned int) , cmp);
unsigned int element;
printf("Enter element to search in the array : \n");
scanf("%u" , &element);
//printf("hey %u ",element);
Binary_Search(array,size,element);

}
