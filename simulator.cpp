#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Overflow: stack is full, cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " at index " << top << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow: stack is empty, cannot pop" << endl;
            return -1;
        }
        int value = arr[top--];
        cout << "Popped " << value << endl;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to peek" << endl;
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack: []" << endl;
            return;
        }
        cout << "Stack (top -> bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter fixed capacity of stack: ";
    cin >> n;

    Stack s(n);

    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3: {
                int t = s.peek();
                if (t != -1) cout << "Top element: " << t << endl;
                break;
            }
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}