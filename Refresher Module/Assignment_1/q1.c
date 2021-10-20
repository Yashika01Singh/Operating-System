#include <stdio.h>

int main(){
	
	FILE *fp1 , *fp2;
	//fp1 points to source file
	//fp2 points to write file
	char character;
	char re[20], wr[20];
	
	// re is name of source file, wr name of dest file
	printf("Enter name for first file:\n");
	scanf("%s",re);
	
	fp1= fopen(re , "r");
	
	if(fp1==NULL )
	{
		printf("Please provide source file that already exist ://");
		return 0;
	}
	printf("Enter name for second file: \n");
	scanf("%s",wr);
	fp2=fopen(wr,"w");
	//reading one character at a time and writing in dest file
	while (fread(&character, 1, 1, fp1) == 1)
    {fwrite(&character, 1, 1, fp2);}
	fclose(fp1);
	fclose(fp2);
	return 0;
}