#include <iostream>
using namespace std;

// ADT for Doubly Linked List
class DoublyLinkedList {
private:
    // Node structure (hidden inside ADT)
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertBeginning(int val) {
        Node* newNode = new Node{val, NULL, head};

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        cout << "Inserted at Beginning\n";
    }

    // Insert at End
    void insertEnd(int val) {
        Node* newNode = new Node{val, NULL, NULL};

        if (head == NULL) {
            head = newNode;
            cout << "Inserted at End\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted at End\n";
    }

    // Insert at Specific Position
    void insertPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1) {
            insertBeginning(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        Node* newNode = new Node{val, temp, temp->next};

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
        cout << "Inserted at Position " << pos << endl;
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
        cout << "Deleted from Beginning\n";
    }

    // Delete from End
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;

        if (temp->next == NULL) {
            head = NULL;
            delete temp;
            cout << "Deleted from End\n";
            return;
        }

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
        cout << "Deleted from End\n";
    }

    // Delete from Specific Position
    void deletePosition(int pos) {
        if (head == NULL || pos <= 0) {
            cout << "Invalid Operation\n";
            return;
        }

        Node* temp = head;

        if (pos == 1) {
            deleteBeginning();
            return;
        }

        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Deleted from Position " << pos << endl;
    }

    // Forward Traversal
    void traverseForward() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        cout << "Forward Traversal: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Backward Traversal
    void traverseBackward() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "Backward Traversal: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Search Element
    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found\n";
    }
};

// Main Function (Menu Driven – Lab Standard)
int main() {
    DoublyLinkedList dll;
    int choice, val, pos;

    do {
        cout << "\n===== DOUBLY LINKED LIST ADT =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Traverse Forward\n";
        cout << "8. Traverse Backward\n";
        cout << "9. Search Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                dll.insertBeginning(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                dll.insertEnd(val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                dll.insertPosition(val, pos);
                break;

            case 4:
                dll.deleteBeginning();
                break;

            case 5:
                dll.deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                dll.deletePosition(pos);
                break;

            case 7:
                dll.traverseForward();
                break;

            case 8:
                dll.traverseBackward();
                break;

            case 9:
                cout << "Enter element to search: ";
                cin >> val;
                dll.search(val);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 0);

    return 0;
}