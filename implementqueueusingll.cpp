#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
public:
    Node* front;
    Node* rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value)
    {
        Node* temp = new Node(value);

        if(front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    int getFront()
    {
        if(front == NULL)
            return -1;

        return front->data;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void display()
    {
        Node* temp = front;

        while(temp != NULL)
        {
            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Front Element: " << q.getFront() << endl;

    q.dequeue();

    cout << "After Dequeue: ";
    q.display();

    cout << "Front Element: " << q.getFront() << endl;

    return 0;
}