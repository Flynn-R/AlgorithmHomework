#include <cstdio>

// Task 1
void getBinary(int a, int* c, int& n)
{
    if (a != 0)
    {
        c[n] = a % 2;
        n++;
        getBinary(a / 2, c, n);
    }
}

// Task 2a
int getPow(int a, int b, int& res)
{
    if (b > 0)
    {
        res *= a;
        b--;
        getPow(a, b, res);
    }
    return res;
}

// Task 2b
int getPowEven(int a, int b, int& res)
{
    if (b > 0)
    {
        if (b % 2 == 0)
        {
            a *= a;
            b /= 2;
        }
        else
        {
            res *= a;
            b--;
        }
        getPowEven(a, b, res);
    }
    else
        return res;
}

#define SIZE 8
int len[SIZE][SIZE];
int field[SIZE][SIZE] = {
        { 1, 0, 0, 1, 0, 0, 0, 1 },
        { 0, 0, 1, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
};

// Task 3
int pathfinder(int i, int j)
{
    if (len[i][j] < 0)
    {
        if (field[i][j])
            return 0;
        else
        {
            if (i == 0 && j > 1)
                return pathfinder(i, j - 1);
            else if (j == 0 && i > 1)
                return pathfinder(i - 1, j);
            else
            {
                if (i == 0 && j == 1)
                    return 1;
                else if (j == 0 && i == 1)
                    return 1;
                else if (len[i - 1][j] < 0)
                    return pathfinder(i, j - 1);
                else if (len[i][j - 1] < 0)
                    return pathfinder(i - 1, j);
                else
                    return pathfinder(i - 1, j) + pathfinder(i, j - 1);
            }
        }
    }
}

int main()
{
    // Task 1
    {
        int c[64], n = 0, a;
        printf("Enter a decimal number: ");
        scanf("%d", &a);
        getBinary(a, c, n);
        for (int i = n - 1; i >= 0; i--)
            printf("%d", c[i]);
        printf("\n");
    }

    // Task 2
    {
        int a, b, res = 1, resEven = 1;
        printf("Enter the base: ");
        scanf("%d", &a);
        printf("Enter the power: ");
        scanf("%d", &b);
        printf("%d\n", getPow(a, b, res));			// Task 2a
        printf("%d\n", getPowEven(a, b, resEven));	// Task 2b
    }

    // Task 3
    /*{
        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE; j++)
            {
                if (i == 0 && j == 0)
                    len[i][j] = 0;
                else
                    len[i][j] = -1;
            }
        }

        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE; j++)
            {
                if (i != 0 || j != 0)
                {
                    len[i][j] = pathfinder(i, j);
                    if (len[i][j] == 0 && i == 0)
                        break;
                    else if (len[i][j] == 0 && j == 0)
                        len[i + 1][j] = len[i - 1][j + 1];
                }
            }
        }

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                printf("%5d", len[i][j]);
            }
            printf("\n");
        }
    }*/
}