#include <iostream>
using namespace std;

// ADT for Circular Linked List
class CircularLinkedList {
private:
    // Node structure (hidden - encapsulation)
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = NULL;
    }

    // Check if list is empty
    bool isEmpty() {
        return (head == NULL);
    }

    // Insert at Beginning
    void insertBeginning(int val) {
        Node* newNode = new Node{val, NULL};

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted at Beginning\n";
    }

    // Insert at End
    void insertEnd(int val) {
        Node* newNode = new Node{val, NULL};

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted at End\n";
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "Deleted from Beginning (Single Node)\n";
            return;
        }

        Node* last = head;
        while (last->next != head)
            last = last->next;

        Node* temp = head;
        head = head->next;
        last->next = head;

        delete temp;
        cout << "Deleted from Beginning\n";
    }

    // Delete from End
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        // Only one node
        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "Deleted from End (Single Node)\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
        cout << "Deleted from End\n";
    }

    // Traverse Circular List
    void traverse() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }

    // Search Element
    void search(int key) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Element not found\n";
    }
};

// Main Function (Menu Driven – Lab Standard ADT)
int main() {
    CircularLinkedList cll;
    int choice, value;

    do {
        cout << "\n===== CIRCULAR LINKED LIST (ADT) =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Traverse List\n";
        cout << "6. Search Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cll.insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                cll.insertEnd(value);
                break;

            case 3:
                cll.deleteBeginning();
                break;

            case 4:
                cll.deleteEnd();
                break;

            case 5:
                cll.traverse();
                break;

            case 6:
                cout << "Enter element to search: ";
                cin >> value;
                cll.search(value);
                break;

            case 0:
                cout << "Program Exited\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 0);

    return 0;
}