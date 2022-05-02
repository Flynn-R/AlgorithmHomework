#include <iostream>

using namespace std;

// Task 1

struct Node
{
    int nodeID;
    Node* next;
};

struct Stack
{
    Node* head;
    size_t size;
};

const size_t SIZE = 10;
const short adjacencyArray[SIZE][SIZE] = {
        { 0, 1, 1, 1, 0, 0, 1, 0, 0, 0 }, // 0
        { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 1
        { 1, 0, 0, 0, 1, 1, 0, 0, 0, 0 }, // 2
        { 1, 1, 0, 0, 0, 0, 0, 0, 1, 0 }, // 3
        { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }, // 4
        { 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 }, // 5
        { 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 }, // 6
        { 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 }, // 7
        { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1 }, // 8
        { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 }, // 9
};
int visited[SIZE];

void init(Stack* stack)
{
    stack->head = nullptr;
    stack->size = 0;
    for (auto &i : visited)
        i = 0;
}

int push(Stack* stack, int nodeID)
{
    auto node = new Node;
    node->next = stack->head;
    node->nodeID = nodeID;
    stack->head = node;
    stack->size++;
    visited[nodeID] = 1;
    return nodeID;
}

int pop(Stack* stack)
{
    if (stack->head == nullptr)
        return NULL;
    Node* temp = stack->head;
    int id = stack->head->nodeID;
    stack->head = stack->head->next;
    delete temp;
    stack->size--;
    return id;
}

void depthTraversal()
{
    auto stack = new Stack;
    init(stack);
    int i = 0;
    int j = 0;
    for (; i < SIZE; i++)
    {
        if (visited[i] == 0)
            cout << push(stack, i) << " ";

        for (; j < SIZE; j++)
        {
            if (adjacencyArray[i][j] && !visited[j])
            {
                cout << push(stack, j) << " ";
                i = j;
                j = -1;
            }
        }
        j = pop(stack);
        if (stack->head != nullptr)
            i = stack->head->nodeID;
    }
}

// Task 2

namespace task2
{
    struct Node
    {
        int nodeID;
        task2::Node* next;
    };
}

struct List
{
    task2::Node* head;
    task2::Node* tail;
    int size;
};

void init(List* queue)
{
    queue->head = nullptr;
    queue->tail = nullptr;
    queue->size = 0;
    for (auto &i : visited)
        i = -1;
}

void push(List* queue, int nodeID)
{
    auto node = new task2::Node;
    node->nodeID = nodeID;
    node->next = nullptr;
    if (queue->tail != nullptr)
        queue->tail->next = node;
    if (queue->head == nullptr)
        queue->head = node;
    queue->tail = node;
    queue->size++;
}

int pop(List* queue)
{
    if (queue->size == 0)
        return NULL;

    task2::Node* temp = queue->head;
    int nodeID;
    if (queue->size == 1)
        nodeID = NULL;
    else
        nodeID = queue->head->next->nodeID;
    queue->head = queue->head->next;
    if (temp == queue->tail)
        queue->tail = nullptr;

    delete temp;
    queue->size--;
    return nodeID;
}

void sort(int* visited)
{
    int temp, pos, indexArray[SIZE];
    for (int i = 0; i < SIZE; ++i)
        indexArray[i] = i;

    for (int i = 1; i < SIZE; ++i)
    {
        temp = visited[i];
        pos = i - 1;
        while (pos >= 0 && visited[pos] < temp)
        {
            visited[pos + 1] = visited[pos];
            indexArray[pos + 1] = indexArray[pos];
            pos--;
        }
        visited[pos + 1] = temp;
        indexArray[pos + 1] = i;
    }
    for (auto i : indexArray)
        cout << i << " ";
}

// Task 2.1
void widthTraversalRecursive(List* queue, int startNode)
{
    if (visited[startNode] == -1 && !adjacencyArray[startNode][startNode])
    {
        push(queue, startNode);
        visited[startNode]++;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        if (adjacencyArray[startNode][i])
        {
            if (visited[i] == -1)
            {
                push(queue, i);
                visited[i]++;
            }
            visited[startNode]++;
        }
    }
    int nextNode = pop(queue);
    if (nextNode != NULL)
        widthTraversalRecursive(queue, nextNode);
}

// Task 2.2
int* widthTraversalAdjacency()
{
    for (int i = 0; i < SIZE; ++i)
    {
        visited[i]++;
        for (int j = 0; j < SIZE; ++j)
        {
            if (adjacencyArray[i][j])
                visited[i]++;
        }
    }
    return visited;
}

int main()
{
    // Task 1
    {
        cout << "Task 1: ";
        depthTraversal();
        cout << endl << endl;
    }

    // Task 2
    {
        auto queue = new List;

        // Task 2.1
        {
            cout << "Task 2.1: ";
            init(queue);
            widthTraversalRecursive(queue, 0);
            sort(visited);
            cout << endl << endl;
        }

        // Task 2.2
        {
            cout << "Task 2.2: ";
            init(queue);
            sort(widthTraversalAdjacency());
            cout << endl << endl;
        }
    }

    return 0;
}