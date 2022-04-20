#include <iostream>
#include <cstdlib>

using namespace std;

#define NODE_SIZE 10000
#define TREE_SIZE 50

struct Tree
{
    int key;
    Tree* left;
    Tree* right;
};

// Task 1

void printBinTree(Tree*);

Tree* buildTree()
{
    Tree* root = nullptr;
    for (size_t i = 0; i < NODE_SIZE; i++)
    {
        Tree* current = root;
        Tree* parent;
        auto newNode = new Tree;
        newNode->key = rand() % NODE_SIZE;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (root == nullptr)
            root = newNode;
        else
        {
            while (current != nullptr)
            {
                parent = current;
                if (newNode->key <= current->key)
                {
                    current = current->left;
                    if (current == nullptr)
                    {
                        parent->left = newNode;
                        break;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == nullptr)
                    {
                        parent->right = newNode;
                        break;
                    }
                }
            }
        }
    }
    //printBinTree(root);
    //cout << endl;
    return root;
}

void createTrees(Tree* trees[])
{
    for (size_t i = 0; i < TREE_SIZE; i++)
        trees[i] = buildTree();
    //cout << endl;
}

void printBinTree(Tree *root)
{
    if (root)
    {
        cout << root->key;
        if (root->left || root->right)
        {
            cout << "(";
            if (root->left)
                printBinTree(root->left);
            else
                cout << "NULL";
            cout << ", ";
            if (root->right)
                printBinTree(root->right);
            else
                cout << "NULL";
            cout << ")";
        }
    }
}

void bypass(Tree* root, int maxCounter, int* depth)
{
    int counter = maxCounter;
    if (root)
    {
        counter++;
        bypass(root->left, counter, depth);
        bypass(root->right, counter, depth);
    }
    if (*depth < counter)
        *depth = counter;
}

float balanceCheck(Tree* trees[])
{
    int totalCounter = 0;
    for (size_t i = 0; i < TREE_SIZE; i++)
    {
        int leftDepth = 0;
        int rightDepth = 0;

        bypass(trees[i]->left, leftDepth, &leftDepth);
        bypass(trees[i]->right, rightDepth, &rightDepth);

        if (abs(leftDepth - rightDepth) <= 1)
            totalCounter++;
    }
    return (static_cast<float>(totalCounter) / TREE_SIZE) * 100;
}

// Task 2

bool search(Tree* root, int key)
{
    if (root == nullptr)
        return false;
    if (root->key == key)
        return true;

    if (search(root->left, key) || search(root->right, key))
        return true;
    else
        return false;
}

int main()
{
    Tree* trees[TREE_SIZE];
    createTrees(trees);

    // Task 1
    {
        cout << "Task 1:" << endl << balanceCheck(trees) << "%" << endl << endl;
    }

    // Task 2
    {
        int number;
        cout << "Task 2:" << endl << "Enter a number which you wish to find in a tree: ";
        cin >> number;
        cout << (search(trees[0], number) ? "True" : "False") << endl << endl;
    }

    return 0;
}