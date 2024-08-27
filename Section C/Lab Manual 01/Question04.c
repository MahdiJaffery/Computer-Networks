#include "Header.h"

char toLower(char val)
{
    if (val >= 'A' && val <= 'Z')
        return val += 32;
    return val;
}

int countVowels(char *word, int end)
{
    int count = 0;
    for (int i = 0; i < end; i++)
        if (toLower(word[i]) == 'a' || toLower(word[i]) == 'e' || toLower(word[i]) == 'o' || toLower(word[i]) == 'u')
            count++;
    return count;
}

char *reverseWord(char *word, int end)
{
    for (int i = 0; i < end / 2; i++)
    {
        char temp = word[i];
        word[i] = word[end - i - 1];
        word[end - i - 1] = temp;
    }

    return word;
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
        return 1;
    }

    char buffer[4096];
    int len = read(readFile, buffer, sizeof(buffer));

    if (len < 0)
    {
        printf("Failed to Read from File: %s\n", argv[1]);

        close(readFile);

        return 2;
    }

    int writeFile = open(argv[2], O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, 0666);

    if (writeFile < 0)
    {
        printf("Failed to Open/Create to File: %s\n", argv[2]);

        close(readFile);

        return 3;
    }

    int wordIndex = 0, start = wordIndex;
    char word[255];

    for (int i = 0; i < len; i++)
    {
        char *reversedWord;
        if (wordIndex > 0)
            start = wordIndex;

        if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
            write(writeFile, &buffer[i], 1);

        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\t')
            word[wordIndex++] = buffer[i];
        else if (wordIndex > 0)
        {
            word[wordIndex] = '\0';

            int vowels = countVowels(word, wordIndex);

            reversedWord = reverseWord(word, wordIndex);

            write(writeFile, reversedWord, sizeof(char) * strlen(reversedWord));

            wordIndex = 0;
        }
    }

    close(readFile);
    close(writeFile);

    return 0;
}