#include "lib.h"

int test_malloc()
{
	int count = 0;
	while (malloc(1000))
	{
		++count;
		if (count % 1000000 == 0)
			printf("count = %d\n", count);
			
	}
	printf("count final = %d\n", count);
	return count;
}