#include "Header.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s\t<Input File> <Output File>\n", argv[0]);
        return 1;
    }

    int writeFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (writeFile < 0)
    {
        printf("Failed to Create File: %s\n", argv[2]);
        return 2;
    }

    int readFile = open(argv[1], O_RDONLY);

    if (readFile < 0)
    {
        printf("Failed to Open File: %s\n", argv[1]);
        return 3;
    }

    char buffer[4096];
    int len = read(readFile, buffer, 4096);

    if (len < 0)
    {
        printf("Failed to Read from File: %s\n", argv[1]);
        return 4;
    }

    for (int i = 0; i < len; i++)
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            printf("Buffer[%d]: %c\n", i, buffer[i]);
            if (write(writeFile, &buffer[i], 1) < 0)
            {
                printf("Failed to Write to File: %s\n", argv[2]);

                close(readFile);
                close(writeFile);

                return 5;
            }
        }

    close(readFile);
    close(writeFile);

    return 0;
}