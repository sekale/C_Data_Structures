#include <stdio.h>

int checkStackGrowthHelper(int *ptr)
{
	int a;
	if(&a < ptr)
	{
		printf("\n ptr: %p", ptr);
		printf("\n &a: %p", &a);
		return 0; //indicates stack growth downwards
	}
	return 1; //indicates stack growth upwards
}

int checkStackGrowth()
{
	int p;
	return checkStackGrowthHelper(&p);
}

int main()
{
	printf("\n Stack Grows: %d", checkStackGrowth());
	return 0;
}