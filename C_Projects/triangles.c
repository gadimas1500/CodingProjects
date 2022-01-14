#include <stdio.h>
int makeTriangle(int height);

int main(void)
{
	int in;
	printf("Enter triangle height: ");
	scanf("%d", &in);
	int some = makeTriangle(in);
	

return 0;
}

int makeTriangle(int height)
{
	int temp = 0;
	while(temp != height)
	{
		printf("%d\t", temp+1);
		for(int i = 0; i < temp+1; i++)
		{
			printf("*\t");		
			
		}
		printf("\n");
		temp++;
	}
	return 0;
}
