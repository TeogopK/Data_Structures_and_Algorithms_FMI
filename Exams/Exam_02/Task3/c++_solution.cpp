// gpt generated
struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

Node* partition(Node* head, int x) {
    if (!head) return head;

    Node* lowerHead = nullptr;
    Node* lowerTail = nullptr;
    Node* higherHead = nullptr;
    Node* higherTail = nullptr;

    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        if (current->value < x) {
            if (!lowerHead) {
                lowerHead = current;
                lowerTail = current;
            } else {
                lowerTail->next = current;
                lowerTail = current;
            }
        } else {
            if (!higherHead) {
                higherHead = current;
                higherTail = current;
            } else {
                higherTail->next = current;
                higherTail = current;
            }
        }
        current->next = nullptr;
        current = nextNode;
    }

    if (lowerTail) lowerTail->next = higherHead;
    return lowerHead ? lowerHead : higherHead;
}
