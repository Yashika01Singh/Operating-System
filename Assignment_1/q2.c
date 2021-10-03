#include <stdio.h>
#include<string.h>

int main(){
	

char number[70];
printf("Enter the number \n");

scanf("%s",number);
size=strlen(number)

unsigned char binnum[32];
int k = 0;
int rem=0;
while(true){
 if(strcmp(number,"0")){
	 break
 }
 divide(&number,&rem);
 binnum[k]=rem;
 k++;

}
}
void divide(char number[] , int rem){

 int temp=0;
 int size=strlen(number);
 char quotient[70] ="";
 for(int i=0 ; i<size ; i++){
	 temp = temp*10 + (int)number[i];
	 if(temp<256){
		continue;
	 }
	 else{
		 int a =temp/256 
		char ch[]=a;
		strncat(quotient , ch ,strlen(ch));
		temp=temp%256;

	 }
 }
number=quotient;
rem=&temp;

}