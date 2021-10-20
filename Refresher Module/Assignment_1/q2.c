#include <stdio.h>
#include<string.h>

int division (char *divident ){
	//Function divides divident string by 256 and stores quotient in divident itself
	//size stores length of divident
    int size= strlen(divident);

    if(size==1 && divident[0] == '0'){
		//in case divident = '0'
        divident[0]='\0';
        return 0;
    }      

    int idx = 0;
	//idx is used as iterator to iterate through digits of the divident
    int temp= 0;
    int iter =0;
    char carry ='0';
    while(divident[idx] != '\0'){
      
        temp += divident[idx] - '0';
        
        if(temp<256){
              if(carry=='1')
              divident[iter++]='0';
             }
        if(temp>=256){
                                   
            divident[iter++]='0' + temp/256; 
            carry = '1';
            temp = temp%256 ;}    
      idx++;
      temp = temp*10;  

      }
	//to handle extra temp = temp*10 command
	temp = temp/10;
	divident[iter] = '\0';
	return temp;}


char tohex(int a){
 //return the hexadecimal digit for an int between 0-15
 if(a<10)
   return (a+'0');
 if(a==10){
   return 'A';
 }
 return a+'A'-10;
  
}


int main(){
    
char a[80] , b[80];
printf("Enter 1st number in decimal format\n" );
 scanf("%s" , a);
printf("Enter 2nd number in decimal format\n" );
scanf("%s" , b);

int i=0 ,j=0;
unsigned char num1[32] , num2[32];

int temp =0;
// convert a to base 256 and store in num 1 

    while(a[0] != '\0'){
    temp = division(a);
    num1[i] = (unsigned char) temp ;
    i++;
    }
// i stores size of num1
temp=0;
// convert b to base 256 and store in num2
while(b[0] != '\0'){
    temp = division(b);
    num2[j] = (unsigned char) temp ;
    j++;
    }
// j stores size of num2
int sum=0;
unsigned char final[33];
int carry = 0;
int finalit=0;

//adding the two numbers and storing in final array
while(sum<i && sum < j){

    temp = (int)num1[sum] + (int)num2[sum] +carry;
    if(temp-256 >= 0){
        carry = 1;
        temp=temp%256;
    }
   
    else 
    {carry=0;}
    final[finalit++]=temp;
    sum++;
    
}
while(sum < i){
    temp=(int)num1[sum]+carry;
    if(temp-256 >=0){
        carry = 1;
        temp=temp%256;
    }
    else 
    {carry=0;}
    final[finalit++]=temp;
    sum++;

}
while(sum < j){
    temp=(int)num1[sum]+carry;
    if(temp-256 >0){
        carry = 1;
        temp=temp%256;
    }
    else 
    {carry=0;}
    final[finalit++]=temp;
    sum++;

}
final[finalit++]=carry;
//printing final array in hexadecimal format
printf("The resultant number in hexadecimal format is : ");
char hex[66];
int iter=0;
temp=0;
char temp2;
for (int m=finalit-1 ; m>-1 ; m--){
    
    temp = final[m];
    temp2=temp%16;
    
    temp=temp/16;
    hex[iter++]=tohex(temp%16 );
    hex[iter++]=tohex(temp2);
}
//printing the hexadecimal
for(int k =0; k<iter ; k++){
    printf("%c " , hex[k]);
}

}

