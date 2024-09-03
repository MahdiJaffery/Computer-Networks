#include "Header.h"

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