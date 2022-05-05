#include <iostream>

using namespace std;

// Task 1
int hashFunc(const char* string)
{
    int i = 0, hash = 0;
    while (string[i] != '\0')
        hash += static_cast<int>(string[i++]);
    return hash;
}

// Task 2
enum Coins
{
    FIFTY = 50, TEN = 10, FIVE = 5, TWO = 2, ONE = 1
};

void greedyBastard(int value)
{
    if (value < 0)
    {
        cout << "You have to give away: ";
        while (value != 0)
        {
            if (value + FIFTY <= 0)
            {
                value += FIFTY;
                cout << FIFTY;
            }
            else if (value + TEN <= 0)
            {
                value += TEN;
                cout << TEN;
            }
            else if (value + FIVE <= 0)
            {
                value += FIVE;
                cout << FIVE;
            }
            else if (value + TWO <= 0)
            {
                value += TWO;
                cout << TWO;
            }
            else if (value + ONE <= 0)
            {
                value += ONE;
                cout << ONE;
            }

            if (value == 0)
                cout << endl;
            else
                cout << " + ";
        }
    }
    else if (value == 0)
        cout << "You don't need any coins" << endl << endl;
    else
    {
        cout << "You have to take: ";
        while (value != 0)
        {
            if (value - FIFTY >= 0)
            {
                value -= FIFTY;
                cout << FIFTY;
            }
            else if (value - TEN >= 0)
            {
                value -= TEN;
                cout << TEN;
            }
            else if (value - FIVE >= 0)
            {
                value -= FIVE;
                cout << FIVE;
            }
            else if (value - TWO >= 0)
            {
                value -= TWO;
                cout << TWO;
            }
            else if (value - ONE >= 0)
            {
                value -= ONE;
                cout << ONE;
            }

            if (value == 0)
                cout << endl;
            else
                cout << " + ";
        }
    }
}

int main()
{
    // Task 1
    {
        cout << "Task 1" << endl << "String: ";
        char buf[256];
        cin >> buf;
        cout << "Hash: " << hashFunc(buf) << endl << endl;
    }

    // Task 2
    {
        cout << "Task 2" << endl << "Sum: ";
        int sum;
        cin >> sum;
        greedyBastard(sum);
        cout << endl;
    }

    return 0;
}