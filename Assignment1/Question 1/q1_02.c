#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
int computeAverage();
int total[6] = {0,0,0,0,0,0};
void* helper(void* args){
    computeAverage("A");
}
int main(){
    pthread_t ptid;
    pthread_create(&ptid , NULL ,helper , (void*)NULL);
    computeAverage("B");
    pthread_join(ptid, NULL);
    printf("Average across sections = \n");
    float f ;
    float two = 2;
    for(int i=0 ; i< 6 ; i++){

        f=total[i] / two;
       
        printf("Average for Assignment %d is %f \n" , i+1 ,f);
    }
    return 0;
    
}
int computeAverage(char Section[]){

int fd;
    fd = open("student_record.csv" , O_RDONLY);
    if(fd<0){
        printf("Error in opening file");
        return 0;
    }
    struct stat st;
    fstat(fd , &st);
    int size = st.st_size;
    char buffer[size];

    int file = read(fd,buffer, size);
    if(file<0){
        printf("Error in reading file");
        return 0;
    }
    
    //printf("%s\n\n" , buffer);
    int assignment[6] = {0,0,0,0,0,0};
    char *iter, *iter2;
    int column=0 , number=0;
    
    for(iter = strtok(buffer , "\n") ; iter!=NULL ; iter = strtok(NULL,"\n"))
    {   
        //strcpy(row , iter);
        column=0;
        number++;
        
        char *rest = NULL;
        for(iter2 = strtok_r(iter , "," ,&rest) ; iter2!= NULL ; iter2 = strtok_r( NULL, "," , &rest)){
            if(column==1 && strcmp(iter2 , Section)){
                number--; 
                break;
            }
            if(column>1){
                
                assignment[column-2]= assignment[column-2]+atoi(iter2);
                
            }
            column++;
            
        }
        
        
    }
    float f;
    
   
    
    for(int i=0 ; i< 6 ; i++){
        f=number;
        f=assignment[i] / f;
        total[i]+=f;
        printf("Average for Assignment %d in Section %s is %f \n" , i+1 ,Section,f);
    }

    
}