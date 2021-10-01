#include <stdio.h>

int main(){
	
	FILE *fp1 , *fp2;
	char character;
	char re[20], wr[20];
	printf("Enter name for first file:\n");
	scanf("%s",re);
	
	fp1= fopen(re , "r");
	
	if(fp1==NULL )
	{
		printf("Please provide files that already exist ://");
		return 0;
	}
	printf("Enter name for second file: \n");
	scanf("%s",wr);
	fp2=fopen(wr,"w");
	while (fread(&character, 1, 1, fp1) == 1)
    {fwrite(&character, 1, 1, fp2);}
	return 0;
}