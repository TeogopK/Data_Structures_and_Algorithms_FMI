class MyLinkedList {
    struct Node {
        int val;
        Node* next = nullptr;
        Node(int val, Node* next = nullptr) : val(val), next(next) {}
    };
    Node* head = nullptr, *tail = nullptr;
    size_t size = 0;
public:
    int get(int index) {
        if(!head) {
            return -1;
        }

        auto iter = head;
        for(int i = 0; iter && i < index; i++, iter = iter->next) {}

        return iter ? iter->val : -1;
    }
    
    void addAtHead(int val) {
        auto newNode = new Node(val);
        if(head) {
            newNode->next = head;
            head = newNode;
        }
        else {
            head = tail = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        auto newNode = new Node(val);
        if(tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        }

        if(index == 0) {
            addAtHead(val);
        } else if(index == size) {
            addAtTail(val);
        } else {
            Node* prev = nullptr;
            Node* curr = head;
            for(int i = 0; i < index; i++) {
                prev = curr;
                curr = curr->next;
            }
            Node* newNode = new Node(val, curr);
            prev->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) {
            return;
        }
        if(index == 0) {
            head = head->next;
            size--;
            if(!head) {
                tail = head;
            }
        }
        else {
            Node* prev = nullptr;
            Node* curr = head;
            for(int i = 0; curr && i < index; i++, prev = curr, curr = curr->next) {}

            if(!curr) {
                return;
            }

            prev->next = prev->next->next;
            size--;
            if(curr == tail) {
                tail = prev;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
