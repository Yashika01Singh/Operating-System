#include<stdio.h>
void selection_sort(int array[] ,int size){
    printf("=> Executing Selection Sort...\n");
int pos,temp;
 for(int i = 0 ; i<size-1 ; i++){
     pos = i;
     for(int j=i+1 ; j<size ; j++){
         if(array[pos]>array[j])
            pos=j;
     }
     //pos is the smallest element in range i:size
     if(pos !=i){

         temp = array[i];
         array[i] = array[pos];
         array[pos]=temp;

            

     }
 }
 for(int i =0 ; i<size ;i++) {
     printf("%d " , array[i]);
 }  
 printf("\n");
}


void bubble_sort(int array[] ,int size){
    printf("=> Executing Bubble Sort...\n");
int temp;
for(int i=0 ; i< size ; i++){
    for(int j=0 ; j<size-i-1 ; j++){

        if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1]=temp;

        }
    }
}
for(int i =0 ; i<size ;i++) {
     printf("%d " , array[i]);
 }  
 printf("\n");
}




void main(){
 int size;
 
 printf("1.Selection Sort \n2.Bubble Sort \n");
 printf("Enter choice of sort :\n");
 char ch;
 scanf("%c" , &ch);
 if(ch !='1' && ch!='2'){
     printf("Enter valid choice\n");
     return;
 }
 printf("Enter number of elements : ");
 scanf("%d" , &size);
 int array[size];
 for(int i=0 ; i<size ;i++){
     scanf("%d" , &array[i]);
 }

 //sending to particular sort according to choice
 if(ch=='1')
 selection_sort(array,size);
 else if(ch=='2')
 bubble_sort(array,size);
 

}