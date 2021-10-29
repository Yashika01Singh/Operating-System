#include <stdio.h>
#include <inttypes.h>

void B(int64_t);
void A(){
    int64_t num;
    printf("Enter Number : ");
    scanf("%ld", &num);
    B(num);
    printf("Back to A");
}
int main(void)
{
    A();
    return 0;
}
