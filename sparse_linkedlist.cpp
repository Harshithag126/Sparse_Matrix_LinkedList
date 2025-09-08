#include <iostream>
using namespace std;

// Node structure for non-zero elements
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

// Class for Sparse Matrix using linked list
class SparseMatrix {
private:
    Node* head;
    int rows, cols;

public:
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
        head = nullptr;
    }

    // Insert a non-zero element
    void insert(int r, int c, int val) {
        if (val == 0) return; // Only store non-zero values

        Node* newNode = new Node{r, c, val, nullptr};

        if (!head) { // First element
            head = newNode;
            return;
        }

        // Insert at the end
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Get value at position
    int getValue(int r, int c) {
        Node* temp = head;
        while (temp) {
            if (temp->row == r && temp->col == c)
                return temp->value;
            temp = temp->next;
        }
        return 0;
    }

    // Print the matrix
    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << getValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~SparseMatrix() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

// Main function
int main() {
    SparseMatrix mat(4, 5);

    // Insert non-zero values
    mat.insert(0, 1, 5);
    mat.insert(1, 3, 8);
    mat.insert(2, 0, 3);
    mat.insert(3, 4, 6);

    cout << "Sparse Matrix using Linked List:" << endl;
    mat.printMatrix();

    return 0;
}
