#include <stdio.h>
#include <math.h>

#define SIZE 4
#define TPK_SIZE 11

// Task 1
int array[SIZE][SIZE] = {
        { 2, 1, 5, 6 },
        { 0, 6, 7, 2 },
        { 9, 5, 1, 9 },
        { 8, 8, 1, 6 }
};

void sortBubble()
{
    for (int i = 0; i < SIZE * SIZE; ++i)
    {
        for (int j = 0; j < SIZE * SIZE; ++j)
        {
            if (*(*array + j) > *(*array + j + 1))
            {
                int temp = *(*array + j + 1);
                *(*array + j + 1) = *(*array + j);
                *(*array + j) = temp;
            }
        }
    }
}

void printArray()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            printf("%5d", array[i][j]);
        }
        printf("\n");
    }
}

// Task 3
int arrTPK[TPK_SIZE];

void TPK()
{
    for (int i = 0; i < TPK_SIZE / 2; ++i)
    {
        int temp = arrTPK[i];
        arrTPK[i] = arrTPK[TPK_SIZE - i - 1];
        arrTPK[TPK_SIZE - i - 1] = temp;
    }

    for (int i = 0; i < TPK_SIZE; ++i)
    {
        float X = sqrt(fabs(arrTPK[i])) + 5 * pow(arrTPK[i], 3);
        if (X > 400)
            printf("ALARM!!!\n");
        else
            printf("%f\n", X);
    }
}

void initArray()
{
    for (int i = 0; i < TPK_SIZE; ++i)
    {
        scanf("%d", &arrTPK[i]);
    }
}

int main()
{
    // Task 1
    printArray();
    printf("\n");
    sortBubble();
    printArray();

    // Task 3
    initArray();
    TPK();
}