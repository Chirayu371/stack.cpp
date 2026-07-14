// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int value;
//     int minVal;
//     Node* next;

//     Node(int v, int m) {
//         value = v;
//         minVal = m;
//         next = NULL;
//     }
// };

// class MinStack {
// private:
//     Node* topNode;

// public:
//     MinStack() {
//         topNode = NULL;
//     }

//     void push(int val) {
//         if (topNode == NULL) {
//             topNode = new Node(val, val);
//         }
//         else {
//             int currMin = min(val, topNode->minVal);

//             Node* newNode = new Node(val, currMin);
//             newNode->next = topNode;
//             topNode = newNode;
//         }
//     }

//     void pop() {
//         if (topNode == NULL) return;

//         Node* temp = topNode;
//         topNode = topNode->next;
//         delete temp;
//     }

//     int top() {
//         if (topNode == NULL) return -1;
//         return topNode->value;
//     }

//     int getMin() {
//         if (topNode == NULL) return -1;
//         return topNode->minVal;
//     }

//     bool empty() {
//         return topNode == NULL;
//     }
// };

// int main() {
//     MinStack st;

//     st.push(5);
//     st.push(2);
//     st.push(8);
//     st.push(1);

//     cout << st.top() << endl;      // 1
//     cout << st.getMin() << endl;   // 1

//     st.pop();

//     cout << st.top() << endl;      // 8
//     cout << st.getMin() << endl;   // 2

//     return 0;
// }

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:

    MinStack() {

    }

    void push(int val) {

        st.push(val);

        if (minSt.empty()) {
            minSt.push(val);
        }
        else {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop() {

        if (st.empty()) {
            cout << "Stack Underflow\n";
            return;
        }

        st.pop();
        minSt.pop();
    }

    int top() {

        if (st.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }

        return st.top();
    }

    int getMin() {

        if (minSt.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }

        return minSt.top();
    }
};