#include "lib.h"



int main()
{


	int pageSize = getpagesize();
	printf("getpagesize = %d\n", pageSize);

	int pid = getpid();
	printf("pid = %d\n", pid);

	const char *fileName = "mapped_memory.txt";

	const int size_file = 25;

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