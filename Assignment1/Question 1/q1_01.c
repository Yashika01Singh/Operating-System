#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int computeAverage();
int main(){
    
    
    
    
    pid_t pid, wpid;
    int status;
    pid = fork();
    if(pid <0){
        printf("fork failed");
    }

    else if(pid == 0){
        //child process code
        computeAverage("A");
        exit(0);

    }
    else {
        //parent process code
        wpid = waitpid(pid, &status,0);
        if(waitpid<0){
            printf("Error in waitpid");
            return 0;
        }
        computeAverage("B");
        
    }
    
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
    printf("Printing averages for Sec %s\n" , Section);
   
    
    for(int i=0 ; i< 6 ; i++){
        f=number;
        printf("Average for Assignment %d is %f \n" , i+1 ,assignment[i] / f);
    }

    
}