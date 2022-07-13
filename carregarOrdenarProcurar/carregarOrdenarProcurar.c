// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION 50

typedef struct reg
{
    int id;
    char description[MAX_DESCRIPTION];
} Register;

void read(Register *reg, int numberList);
void order(Register *reg, int numberList);
void print(Register *reg, int numberList);
void search(Register *reg, int numberList, char key[MAX_DESCRIPTION]);

int main()
{
    int numberList;
    char key[MAX_DESCRIPTION];

    printf("Records number = ");
    scanf("%d", &numberList);

    printf("Search = ");
    fflush(stdin);
    gets(key);

    Register *reg = (Register *)malloc(numberList * sizeof(Register));

    read(reg, numberList);
    order(reg, numberList);
    print(reg, numberList);
    search(reg, numberList, key);

    return 0;
}

void order(Register *reg, int numberList)
{
    int y;
    do
    {
        y = 0;
        for (int i = 0; i < numberList; i++)
        {
            if ((strncmp(reg[i].description, reg[i + 1].description, strlen(reg[i].description)) > 0) && (i + 1 < numberList))
            {
                Register temp = reg[i];
                reg[i] = reg[i + 1];
                reg[i + 1] = temp;
                y++;
            }
        }
    } while (y > 0);
}
void read(Register *reg, int numberList)
{
    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = ");
        scanf("%d", &reg[i].id);
        printf("Register.Description = ");
        fflush(stdin);
        gets(reg[i].description);
    }
}
void print(Register *reg, int numberList)
{
    printf("\n==================================================================\n");
    for (int i = 0; i < numberList; i++)
    {
        printf("\nRegister.ID = %d\n", reg[i].id);
        printf("Register.Description = %s\n", reg[i].description);
    }
    printf("\n==================================================================\n");
}
void search(Register *reg, int numberList, char key[MAX_DESCRIPTION])
{
    int low, high, mid;
    low = 0;
    high = numberList - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(key, reg[mid].description) < 0)
        {
            high = mid - 1;
        }
        else if (strcmp(key, reg[mid].description) > 0)
        {
            low = mid + 1;
        }
        else
        {
            printf("\n==================================================================\n");
            printf("\n\t\tRegister.ID = %d\n", reg[mid].id);
            printf("\t\tRegister.Description = %s\n", reg[mid].description);
            printf("\n==================================================================\n");
            break;
        }
    }
}
