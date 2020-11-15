/*Queue - Linked List implementation*/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};
// Two glboal variables to store address of front and rear nodes.
Node* front = NULL;
Node* rear = NULL;

// To Enqueue an integer
void Enqueue(int x)
{
    Node* temp = new Node();
    temp->data =x;
    temp->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// To Dequeue an integer.
void Dequeue()
{
//	struct Node* temp = front;
    if(front == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }
    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    //free(temp);
}

int Front()
{
    if(front == NULL)
    {
        cout<<"Queue is empty\n";
        return 0;
    }
    return front->data;
}

void Print()
{
    struct Node* temp = front;
    while(temp != NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    /* Drive code to test the implementation. */
    // Printing elements in Queue after each Enqueue or Dequeue
    Enqueue(2);
    Print();
    Enqueue(4);
    Print();
    Enqueue(6);
    Print();
    Dequeue();
    Print();
    Enqueue(8);
    Print();
}
