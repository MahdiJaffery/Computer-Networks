#include "Header.h"

int isAlpha(char val)
{
    return (val >= 'a' && val <= 'z') || (val >= 'A' && val <= 'Z');
}

int isNum(char val)
{
    return val >= '0' && val <= '9';
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s\t<Input File> <Output File>\n", argv[0]);
        return 1;
    }

    int readFile = open(argv[1], O_RDONLY);

    if (readFile < 0)
    {
        printf("Failed to Open File: %s\n", argv[1]);

        return 2;
    }

    char buffer[4096];

    int len = read(readFile, buffer, sizeof(buffer));

    if (len < 0)
    {
        printf("Failed to Read from File: %s\n", argv[1]);
        return 3;
    }

    int writeFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (writeFile < 0)
    {
        printf("Failed to Create/Open File: %s\n", argv[2]);
        return 4;
    }

    int start = 0, end = 0, flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (!isAlpha(buffer[i]) && !isNum(buffer[i]) || buffer[i] == ' ')
        {
            if (write(writeFile, &buffer[i], 1) < 0)
            {
                printf("Failed to Write to File: %s\n", argv[2]);

                close(readFile);
                close(writeFile);

                return 5;
            }
        }
    }

    close(readFile);
    close(writeFile);

    return 0;
}