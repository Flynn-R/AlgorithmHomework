#include "geek.h"

#define SIZE 10

// Task 1

typedef struct
{
    int priority;
    int value;
} Element;

Element* array[SIZE];
int end = -1;

void init()
{
    for (int i = 0; i < SIZE; ++i)
        array[i] = nullptr;
}

void insert(int prior, int val)
{
    auto* element = (Element*) malloc(sizeof(Element));
    element->priority = prior;
    element->value = val;

    if (end < SIZE - 1)
        array[++end] = element;
    else
        printf("The queue is full! Delete an element before attempting again.\n");
}

void Delete()
{
    if (end != -1)
    {
        int max = 0;
        for (int i = 1; i < SIZE - 1; ++i)
        {
            if (array[i]->priority > array[max]->priority)
                max = i;
        }

        while (max <= end)
        {
            if (max == end)
                array[max] = nullptr;
            else
                array[max] = array[max + 1];
            max++;
        }
        end--;
    }
    else
        printf("The queue is empty! Add elements first.\n");
}

void printArr()
{
    for (int i = 0; i <= end; ++i)
    {
        printf("[%d, %d] ", array[i]->priority, array[i]->value);
    }
    printf("\n");
}

// Task 2

int currentPos = -1;
int arr[SIZE];

void push(int value)
{
    if (currentPos < SIZE - 1)
        arr[++currentPos] = value % 2;
    else
        printf("Stack overflow!\n");
}

int pop()
{
    if (currentPos != -1)
        return arr[currentPos--];
    else
        printf("Stack is empty!\n");
    return -1;
}

void translation(int number)
{
    do
    {
        push(number);
        number /= 2;
    } while (number != 0);

    do
    {
        printf("%d", pop());
    } while (currentPos != -1);
    printf("\n");
}

int main()
{
    // Task 1
    {
        init();
        for (int i = 0; i < SIZE; ++i)
        {
            int prior = rand() % 10;
            int val = rand() % 100;

            insert(prior, val);
        }
        printArr();

        Delete();
        printArr();
        Delete();
        printArr();
        insert(0, 0);
        printArr();
        insert(0, 1);
        printArr();
        insert(0, 2);
        printArr();
    }

    // Task 2

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    translation(num);

    return 0;
}