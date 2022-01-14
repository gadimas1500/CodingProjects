#include <stdio.h>
int factorial(int num);

int main(void)
{
	while(1)
	{
	int in;
	int out;
	printf("Enter a number: ");
	scanf("%d", &in);
	out = factorial(in);
	printf("This is the output: %d\n", out);
	printf("\n");
}


return 0;
}

int factorial(int num)
{
	int ret = 1;
	for(int i = 1; i <= num; i++)
	{
		ret *= i;
	}

	return ret;
}
