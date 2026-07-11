#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertBack(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Delete a value
    void deleteNode(int value) {
        if (head == nullptr)
            return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Search value
    bool search(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value)
                return true;

            current = current->next;
        }

        return false;
    }

    // Display list
    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL\n";
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};


int main() {

    LinkedList list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    cout << "Linked List: ";
    list.display();

    list.insertFront(5);

    cout << "After inserting 5: ";
    list.display();

    cout << "Search 20: ";

    if (list.search(20))
        cout << "Found\n";
    else
        cout << "Not Found\n";


    list.deleteNode(20);

    cout << "After deleting 20: ";
    list.display();

    return 0;
}
