#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

class Stack
{
    Node* top;

public:

    Stack()
    {
        top=NULL;
    }

    void push(int x)
    {
        Node* newNode=new Node(x);

        newNode->next=top;

        top=newNode;
    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack Underflow\n";
            return;
        }

        Node* temp=top;
        top=top->next;
        delete temp;
    }

    int peek()
    {
        if(top==NULL)
            return -1;

        return top->data;
    }

    bool isEmpty()
    {
        return top==NULL;
    }

    void display()
    {
        Node* temp=top;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

        cout<<endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();   // 30 20 10

    s.pop();

    s.display();   // 20 10

    cout<<s.peek();
}