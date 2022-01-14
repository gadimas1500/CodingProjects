#include <stdio.h>
int power(int base, int exp);

int main(void)
{
	int b, e;
	printf("Enter the base: ");
	scanf("%d", &b);
	printf("Enter the power: ");
	scanf("%d", &e);
	
	printf("Here is the answer: %x\n", power(b, e));




return 0;
}

int power(int base, int exp)
{
	int ret = 1;
	for(int i = 0; i < exp; i++)
	{
		ret *= base;
	}


	return ret;
}
