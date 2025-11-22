// gpt generated

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

Node* partition(Node* head, int x) {
    if (!head) return head;

    Node* lowerHead = new Node(0); // Sentinel node for elements less than x
    Node* lowerTail = lowerHead;    // Tail of the lower list
    Node* higherHead = new Node(0); // Sentinel node for elements greater or equal to x
    Node* higherTail = higherHead;  // Tail of the higher list

    Node* current = head;
    while (current) {
        if (current->value < x) {
            lowerTail->next = current;
            lowerTail = lowerTail->next;
        } else {
            higherTail->next = current;
            higherTail = higherTail->next;
        }
        current = current->next;
    }

    lowerTail->next = higherHead->next; // Connect lower list to higher list
    higherTail->next = nullptr;         // End of the new list

    Node* newHead = lowerHead->next;
    delete lowerHead; // Remove sentinel node
    delete higherHead; // Remove sentinel node

    return newHead;
}
