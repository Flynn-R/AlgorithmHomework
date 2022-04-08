#include "geek.h"

void insertSort(int* arr, int len)
{
    int temp, pos;
    for (int i = 1; i < len; i++)
    {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void quickSort(int* arr, int first, int last)
{
    int len = first + last + 1;
    if (len <= 10)
        insertSort(arr, len);
    else
    {
        int i = first, j = last;
        int x = arr[(first + last) / 2];
        do
        {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if (i <= j) swapInt(&arr[i++], &arr[j--]);
        } while (i <= j);
        if (i < last) quickSort(arr, i, last);
        if (j > first) quickSort(arr, first, j);
    }
}

void improvedQuickSort(int* arr, int first, int last)
{
    int mid = (first + last) / 2;
    if (arr[mid] < arr[first] && arr[first] < arr[last] || arr[last] < arr[first] && arr[first] < arr[mid])
    swapInt(&arr[first], &arr[mid]);
    else if (arr[first] < arr[last] && arr[last] < arr[mid] || arr[mid] < arr[last] && arr[last] < arr[first])
        swapInt(&arr[last], &arr[mid]);
    quickSort(arr, first, last);
}

void evenBucketSort(int* arr, int len)
{
    const int max = len;
    const int b = 10;
    int buckets[b][max + 1];
    for (int i = 0; i < b; i++)
        buckets[i][max] = 0;
    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        for (int i = 0; i < max; i++)
        {
            if (arr[i] % 2 == 0)
            {
                int d = (arr[i] / digit) % b;
                buckets[d][buckets[d][max]++] = arr[i];
            }
        }
        int index = 0;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < buckets[i][max]; j++)
            {
                if (arr[index] % 2 == 0)
                    arr[index++] = buckets[i][j];
                else
                {
                    index++;
                    j--;
                }
            }
            buckets[i][max] = 0;
        }
    }
}

#define SIZE 20

int main()
{
    int array[SIZE];
    fillIntRandom(array, SIZE, 100);
    printIntArray(array, SIZE, 3);
    improvedQuickSort(array, 0, SIZE - 1);
//	evenBucketSort(array, SIZE);
    printIntArray(array, SIZE, 3);

    return 0;
}
