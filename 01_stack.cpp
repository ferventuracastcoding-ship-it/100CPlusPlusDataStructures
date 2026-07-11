#include <iostream>
using namespace std;

// Node for stack
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push element onto stack
    void push(int value) {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }

    // Remove top element
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        top = top->next;

        delete temp;
    }

    // Return top element
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }

        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display stack
    void display() {
        Node* current = top;

        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};


int main() {

    Stack stack;

    // Add elements
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    cout << "Stack elements:\n";
    stack.display();

    cout << "\nTop element: ";
    cout << stack.peek() << endl;

    stack.pop();

    cout << "\nAfter pop:\n";
    stack.display();

    return 0;
}
