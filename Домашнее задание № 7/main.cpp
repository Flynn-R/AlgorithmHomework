#include <iostream>

struct Node
{
	char data;
	Node* next;
};

struct Stack
{
	Node* head;
	int size;
};

void init(Stack* stack)
{
	stack->head = nullptr;
	stack->size = 0;
}

void push(Stack* stack, char data)
{
	auto node = new Node;
	node->data = data;
	node->next = nullptr;
	if (stack->size == 0)
		stack->head = node;
	else
	{
		Node* current = stack->head;
		while (current->next != nullptr)
			current = current->next;
		current->next = node;
	}
	stack->size++;
}

void printStack(Stack* stack)
{
	Node* current = stack->head;
	for (int i = 0; i < stack->size; ++i)
	{
		std::cout << current->data;
		std::cout << ((i == stack->size - 1) ? "\n" : ", ");
		current = current->next;
	}
}

// Task 1

bool popBrackets(Stack* stack)
{
	Node* current = stack->head;
	Node* parent = nullptr;
	if (current->data == ')' || current->data == ']' || current->data == '}')
		return false;

	while (current->next->data == '(' || current->next->data == '[' || current->next->data == '{')
	{
		parent = current;
		current = current->next;
	}

	switch (current->data)
	{
		case '(':
			if (current->next->data != ')')
				return false;
			break;
		case '[':
			if (current->next->data != ']')
				return false;
			break;
		case '{':
			if (current->next->data != '}')
				return false;
			break;
		default:;
	}
	if (current == stack->head)
		stack->head = current->next->next;
	else
		parent->next = current->next->next;
	delete current->next;
	delete current;
	stack->size -= 2;
	return true;
}

bool sequenceCheck(Stack* stack, char* sequence)
{
	for (int i = 0; sequence[i] != '\0'; ++i)
	{
		if (sequence[i] == '(' || sequence[i] == '[' || sequence[i] == '{' ||
		sequence[i] == ')' || sequence[i] == ']' || sequence[i] == '}')
			push(stack, sequence[i]);
	}
	if (stack->size % 2 != 0)
		return false;

	while (stack->size != 0)
	{
		if (!popBrackets(stack))
			return false;
	}
	return true;
}

// Task 2

Stack* copy(Stack* stack)
{
	auto copiedStack = new Stack;
	init(copiedStack);
	Node* current = stack->head;
	if (current != nullptr)
	{
		do
		{
			push(copiedStack, current->data);
			current = current->next;
		} while (current != nullptr);
	}
	return copiedStack;
}

// Task 3

bool sortCheck(Stack* stack)
{
	Node* current = stack->head;
	if (current != nullptr)
	{
		while (current->next != nullptr)
		{
			if (current->data > current->next->data)
				return false;
			current = current->next;
		}
	}
	return true;
}

int main()
{
	// Task 1
	{
		std::cout << "Task 1: ";
    		auto stack = new Stack;
	  	init(stack);
		char buf[] = "[2/{5*(4+7)}]";
		if (sequenceCheck(stack, buf))
			std::cout << "All good!" << std::endl << std::endl;
		else
			std::cout << "Fubar!" << std::endl << std::endl;
		delete stack;
	}

	// Task 2
	{
		std::cout << "Task 2: ";
    		auto stack = new Stack;
		init(stack);
		push(stack, 'a');
		push(stack, 'b');
		push(stack, 'c');
		push(stack, 'd');

		printStack(copy(stack));
		std::cout << std::endl;
		delete stack;
	}

	// Task 3
	{
		std::cout << "Task 3: ";
		auto stack = new Stack;
		init(stack);
		push(stack, 'a');
		push(stack, 'b');
		push(stack, 'c');
		push(stack, 'd');
		push(stack, 'e');
		push(stack, 'f');
		push(stack, 'g');

		std::cout << ((sortCheck(stack)) ? "Sorted" : "Not sorted");
		std::cout << std::endl << std::endl;
		delete stack;
	}

	return 0;
}