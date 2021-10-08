#include <stdio.h>
#include<string.h>
int division (char *divident ){
    int size=strlen(divident);
    
    char quotient[size];
    int j=0;
    int i=0;
    int temp=0;
    
    
    
    while(divident[i+1]!='\0'){
        
         
        temp+=divident[i]-'0';
        
        if (temp <256){
        temp = temp*10; 
        i++;
        continue;
        }
        if(temp>=256){
            
            int f = temp/256;

            quotient[j]=f + '0';
            
            temp=temp%256;
            j++;
        }
        i++;
    }
   
temp+=divident[i]-'0';
  
if(temp<256){
    quotient[j]=0+'0';
    j++;
} 
if(temp>=256){
            
            int f = temp/256;

            quotient[j]=f + '0';
            
            temp=temp%256;
            //printf("quotient %s , rem %d \n" ,quotient,temp);
        }

strcpy(divident,quotient);
return temp;
}
int main(){
	

/*char number[70];
printf("Enter the number \n");

scanf("%s",number);
size=strlen(number)

*/
char a[]="12";

int indi=0;
unsigned char final[2];
while(1){
    
    if(strcmp(a , "0") == 0){
        break;
    }

    final[indi] = (unsigned char)division(a) ;
    
    //printf("bin till now = binary[i] %c" , final[i]);
    indi++;

    

}
printf("%lu    \n %d " , strlen(final) ,indi);



}
