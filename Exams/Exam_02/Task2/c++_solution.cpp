// gpt generated

Node* positiveStalinSort(Node* list) {
    if (!list) return nullptr;

    Node* head = list;

    // Премахваме отрицателните в началото
    while (head && head->data < 0) {
        Node* temp = head;
        head = head->next;
        delete temp;  // Изтриваме възел за предотвратяване на утечки
    }

    Node* current = head;
    while (current && current->next) {
        // Свързваме текущия с по-следващия елемент, изтривайки по-малкия следващ
        if (current->data > current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;  // Изтриваме възел за предотвратяване на утечки
        } else {
            current = current->next;
        }
    }

    return head;
}
