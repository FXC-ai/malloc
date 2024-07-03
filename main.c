#include "lib.h"


int main()
{

	test_malloc();
	int pageSize = getpagesize();
	printf("getpagesize = %d\n", pageSize);

	int pid = getpid();
	printf("pid = %d\n", pid);

	const char *fileName = "maped_memory.txt";

	const int size_file = 25;

	char *ptr_test = (char *) malloc (sizeof(char) * 4);

	// ptr_test[0] = 'a';
	// ptr_test[1] = 'a';
	// ptr_test[2] = 'a';
	// ptr_test[3] = '\0';


	int c = 0;

	while (c < 3)
	{
		ptr_test[c] = 'a';
		c++;
	}
	ptr_test[c] = '\0';
	printf("ptr_test : %s\n", ptr_test);



	int fd = open(fileName, O_RDWR | O_CREAT, 0400 | 0200);

	if (fd == -1)
	{
		perror("open");
		return 1;
	}

	if (ftruncate(fd, size_file) == -1)
	{
		perror("ftruncate");
		return 1;
	}

	void *file_memory = mmap(NULL, size_file, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (file_memory == MAP_FAILED)
	{
		perror("mmap");
		close(fd);
		return 1;
	}

	const char * msg = "only a test";
	strncpy(file_memory, msg, strlen(msg));

	printf("content of the file memory : %s",(char *)file_memory);

	munmap(file_memory, size_file);
	close(fd);

	return 0;
}