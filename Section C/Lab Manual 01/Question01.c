#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char fileName[100];

    if (argc != 2)
    {
        printf("Usage: %s\t<Input File>", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    char buffer[4096];

    int len = read(fd, buffer, 4096);

    printf("File Holds:\n%s\n", buffer);

    return 0;
}