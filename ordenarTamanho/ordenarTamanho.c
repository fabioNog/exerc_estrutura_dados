// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_STR 500

typedef struct words
{
    char str[MAX_STR];
} Words;

int splitMatrix(char *string, Words *words);
void order(Words *words, int size);
void print(Words *words, int size);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Words *words = (Words *)malloc(50 * sizeof(Words));
    char str[MAX_STR];
    int size = 0;

    fgets(str, sizeof(str), stdin);
    size = splitMatrix(str, words);
    order(words, size);
    print(words, size);
    free(words);

    return 0;
}

int splitMatrix(char *string, Words *words)
{
    int i = 0;

    char *token = strtok(string, " ");
    while (token != NULL)
    {
        strcpy(words[i].str, token);
        token = strtok(NULL, " ");
        i++;
    }

    return i;
}
void order(Words *words, int size)
{
    int y;
    do
    {
        y = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (strlen(words[i].str) > strlen(words[i + 1].str))
            {
                Words temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
                y++;
            }
        }
    } while (y > 0);
}
void print(Words *words, int size)
{
    setlocale(LC_ALL, "Portuguese");
    int i = 0;
    do
    {
        printf("%s ", words[i].str);
        i++;
    } while (i < size);
}