#include <iostream>

using namespace std;

void printMessage(char*);
//void printArr(char**, int, int);

// Task 1

void caesarEncryption(char* message, int column)
{
    if (column < 0)
        column += 26;
    for (size_t i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 65 && message[i] <= 90)
            message[i] = (message[i] - 65 + column) % 26 + 65;
        else if (message[i] >= 97 && message[i] <= 122)
            message[i] = (message[i] - 97 + column) % 26 + 97;
        else
            message[i] = '*';
    }

    cout << "Encrypted message: ";
    printMessage(message);
}

void caesarDecryption(char* message, int column)
{
    if (column > 0)
        column -= 26;
    for (size_t i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 65 && message[i] <= 90)
            message[i] = (message[i] - 65 - column) % 26 + 65;
        else if (message[i] >= 97 && message[i] <= 122)
            message[i] = (message[i] - 97 - column) % 26 + 97;
        else
            message[i] = '*';
    }

    cout << "Decrypted message: ";
    printMessage(message);
}

// Task 2

char** initArray(char* message, int row, int column)
{
    auto array = new char*[row];
    for (size_t j = 0; j < row; j++)
        array[j] = new char[column];

    return array;
}

void simpleRearrangementEncryption(char* message, int column)
{
    int row;
    for (row = 0; message[row] != '\0'; row++);
    row = (row % column == 0) ? row / column : row / column + 1;
    char **array = initArray(message, row, column);

    int k = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            if (message[k] != '\0')
                array[i][j] = message[k++];
            else
                array[i][j] = '*';
        }
    }
    k = 0;
    for (size_t i = 0; i < column; i++)
    {
        for (size_t j = 0; j < row; j++)
            message[k++] = array[j][i];
    }
    //printArr(array, row, column);

    for (size_t i = 0; i < row; i++)
        delete array[i];
    delete array;

    cout << "Encrypted message: ";
    printMessage(message);
}

void simpleRearrangementDecryption(char* message, int row)
{
    int column;
    for (column = 0; message[column] != '\0'; column++);
    column /= row;
    char** array = initArray(message, row, column);

    int k = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            if (message[k] != '\0')
                array[i][j] = message[k++];
            else
                array[i][j] = '*';
        }
    }
    k = 0;
    for (size_t i = 0; i < column; i++)
    {
        for (size_t j = 0; j < row; j++)
            message[k++] = array[j][i];
    }
    //printArr(array, row, column);

    for (size_t i = 0; i < row; i++)
        delete array[i];
    delete array;

    cout << "Decrypted message: ";
    printMessage(message);
}

/*void printArr(char** array, int row, int column)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}*/

void printMessage(char* message)
{
    for (size_t i = 0; message[i] != '\0'; i++)
        cout << message[i];
    cout << endl;
}

int main()
{
    // Task 1
    {
        int key;
        char message[256];
        cout << "Task 1" << endl << "Enter a message: ";
        cin >> message;
        cout << "Enter a key: ";
        cin >> key;
        caesarEncryption(message, key);
        caesarDecryption(message, key);
        cout << endl;
    }

    // Task 2
    {
        int key;
        char message[256];
        cout << "Task 2" << endl << "Enter a message: ";
        cin >> message;
        cout << "Enter a number of columns: ";
        cin >> key;
        simpleRearrangementEncryption(message, key);
        simpleRearrangementDecryption(message, key);
        cout << endl;
    }

    return 0;
}