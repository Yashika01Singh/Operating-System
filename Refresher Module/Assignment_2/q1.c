#include <stdio.h>
#include <stdlib.h>
void show(int *p[] , int length[6]){
    //function for printing the given matrix
    printf("\n");
    for(int i=0; i<6 ; i++){
    for(int j=0;j<length[i];j++){
        printf("%d ",*(p[i]+j));
    }
    printf("\n");
}

}

int main(){
int *p[6];
//length array store length of each row
int length[6]={7,4,6,3,7,2};


for(int row=0; row<6 ; row++){
//allocating memory
p[row] = (int*) malloc(length[row]*sizeof(int));

for(int j=0 ; j< length[row]; j++){
    *(p[row]+j)=rand() % 11;
    //assigning random value to all elements in the array      

    }
}
show(p,length);
int size;

while(1){
    printf("Enter row for which you want to change number of columns, enter -1 to quit , -2 to show:");

    int row ;
    scanf("%d",&row);
    if(row==-2){
        show(p,length);
        continue;
    }
    if(row==-1){
        break;
    }


    printf("Ennter new number of columns for row %d :" , row);
    row--;
    scanf("%d",&size);
    length[row]=size;
    p[row] = realloc(p[row],size*sizeof(int));
    for(int j=0 ; j< size ; j++){
        //assigning random value to all elements in the array 
        *(p[row]+j)=rand() % 11;        
    }
    
}

for(int i=0; i<6 ; i++){
    //freeing memory we allocated dynamically
    free(p[i]);
}


}