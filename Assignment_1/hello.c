#include <stdio.h>

int main(){
	int a = 2, b = 4;
	int c;
	c=a;
	a=b;
	b=c;
	printf("%d %d\n", a, b);
	return 0;
}