#include <stdio.h>
int main(void)
{
	int far;
	
	printf("Enter temperature in F: ");
	scanf("%d", &far);	//WE GET THE ADDRESS OF far AND STORE THE INPUT INTO THAT ADDRESS
	float cel = (far - 32) * (float)5/9;	//CASTING AND INT AS A FLOAT
	float kelvin = cel + 273.15;
	printf("Farenheit: %d Address: %p\n", far, &far);
	printf("Celcius: %.3f Address: %p\n", cel, &cel);
	printf("Kelvin: %.3f Address: %p\n", kelvin, &kelvin);




return 0;
}
