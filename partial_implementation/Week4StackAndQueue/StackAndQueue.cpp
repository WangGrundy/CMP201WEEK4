// William Kavanagh, CMP201.2022
// AX1.2 Partial Implementation

#include <iostream>
#include "StackAndQueue.h"

// Default constructor, init array
ArrayStack::ArrayStack()
{
    arr = new int[capacity];
}

// Remove first element, return value.
int ArrayStack::Pop()
{
    // TODO: ASSESSED [1]
    if (stackTop == -1) {
        return 0;
    }

    int topOfStack = arr[stackTop]; //top of stack element
    stackTop -= 1;

    return topOfStack;
}

// Check first element, return value.
int ArrayStack::Peek()
{
    // TODO: ASSESSED [0.5]
    return arr[stackTop];
}

// Add element to top of stack, 
// calls DoubleArray() where appropriate
void ArrayStack::Push(int n)
{
    // TODO: ASSESSED [1]
    // [0.5] if correct without resizing.
    if (stackTop == capacity - 1) //if stack is full (in this case, its an Raw array)
    {
        DoubleArray();
    }

    stackTop += 1; // ++ new stack layer
    arr[stackTop] = n; //set value

    
}

// Print elements in Stack neatly
// DO NOT CHANGE: used for testing and assessment
void ArrayStack::Display()
{
    std::cout << arr[0] << "\t<- head" << std::endl;
    for (int i = 1; i < stackTop + 1; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

// Updates array pointer to new array of double the size
// elements are copied in from old array with position preserved.
void ArrayStack::DoubleArray()
{
    capacity *= 2;
    int* new_arr = new int[capacity];
    for (int i = 0; i < stackTop + 1; i++)
    {
        new_arr[i] = arr[i];
    }
    arr = new_arr;
}

// Node constructor
Node::Node(int n)
{
    next = nullptr;
    data = n;
}

// QL constructor
QueueList::QueueList()
{
    // TODO: ASSESSED [0.5]
    front = nullptr;
    back = nullptr;
}

// Add item to back of queue
void QueueList::Enqueue(int n)
{
    // TODO: ASSESSED [1]
    if (front == nullptr) { //if no head
        back = new Node(n);
        front = back;
        return;
    }

    //if there is a head (front)
    back->next = new Node(n); //last node points to new last node
    back = back->next; //set the variable back in the queueList to be the new end of queue
}

// Remove item from front of queue
int QueueList::Dequeue()
{
    if (front == nullptr) { //sanity check
        return 0;
    }

    // TODO: ASSESSED [1]
    int itemToReturn = front->data; //sets the item to return to be the first element in the ll
    front = front->next; //set front to be the one behind the first
    return itemToReturn;
}

// Print elements in Stack neatly
// DO NOT CHANGE: used for testing and assessment
void QueueList::Display()
{
    if (!front)
    {
        std::cout << "[]";
        return;
    }
    Node* n = front;
    std::cout << "f: ";
    while (n != back)
    {
        std::cout << n->data << ",\t";
        n = n->next;
    }
    std::cout << "b: " << n->data << std::endl;
}

//int main()
//{
//   // Stack test.
//
//   ArrayStack* stack = new ArrayStack();
//   stack->Push(20);
//   stack->Push(30);
//   stack->Push(40);
//   std::cout << "Testing stack, expecting: \nh:20,\t30,\t40.\nGot: \n";
//   stack->Display();
//   std::cout << "\n";
//   stack->Pop();
//   stack->Push(50);
//   std::cout << "Show me 50: " << stack->Peek() << "\n";
//   std::cout << "Testing stack, expecting: \nh:20,\t30,\t50\nGot: \n";
//   stack->Display();
//
//   // Check Overflow
//
//   ArrayStack* bigStack = new ArrayStack();
//   for (int i = 0; i < 100; i++)
//   {
//       bigStack->Push(i);
//   }
//   std::cout << "Expecting stack of 0..99:\n";
//   bigStack->Display();
//   std::cout << "Expecting stack capacity of 2^7. capacity is actually: " << bigStack->capacity << "\n";
//
//
//   // Queue test.
//
//   QueueList* q = new QueueList();
//   q->Enqueue(25);
//   q->Enqueue(40);
//   q->Enqueue(7);
//   std::cout << "Testing queue, expecting: \nf: 25,\t40,\tb: 7\nGot: \n";
//   q->Display();
//
//   q->Dequeue();           // remove 25 from queue, do nothing with it.
//   q->Enqueue(45);
//   std::cout << "Testing queue, expecting: \nf: 40,\t7,\tb: 45\nGot: \n";
//   q->Display();
//
//   return 0;
//}