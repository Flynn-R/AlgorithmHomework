#include <cstdio>

bool isPrimeCheck(int A)
{
    int Q = 2;

    while (A != Q)
    {
        if (A % Q == 0)
            return false;
        else
            Q++;
    }

    return true;
}

int main()
{
    int A;
    printf("Enter a number: ");
    scanf("%d", &A);

    if (isPrimeCheck(A))
        printf("The number is prime\n");
    else
        printf("The number is not prime\n");

    return 0;
}