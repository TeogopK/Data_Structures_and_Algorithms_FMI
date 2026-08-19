struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* processList(Node* head) {
    if (!head) {
        return new Node(0);
    }

    int removedCount = 0;
    int previousValue = head->data;

    Node* last = head;
    Node* current = head->next;

    while (current) {
        Node* next = current->next;
        int currentValue = current->data;

        if (currentValue == previousValue + 1) {
            last->next = next;
            delete current;
            removedCount++;
        } else {
            last = current;
        }

        previousValue = currentValue;
        current = next;
    }

    last->next = new Node(removedCount);

    return head;
}