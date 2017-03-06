#include <stdio.h>

int checkStackGrowthHelper(int *ptr)
{
	int a;
	if(&a < ptr)
	{
		printf("\n ptr: %p", ptr);
		printf("\n &a: %p", &a);
		return 0;
	}
	return 1;
}

int checkStackGrowth()
{
	int p;
	return checkStackGrowthHelper(&p);
}

int main()
{
	printf("\n Stack Grows: %d", checkStackGrowth());
}