// https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3729

void SinglyLinkedList::replace(int X) {
    if(!head || X == 1)
        return;
    
    Node* curr = head;
    Node* prev = nullptr;
    
    while(curr) {
        if(curr->value == X) {
            Node* beg = new Node(1);
            Node* end = beg;
          
            for(int i = 1; i < X; i++) {
                end->next = new Node(1);
                end = end->next;
            }
            
            if(!prev) {
                head = beg;
            }
            else {
                prev->next = beg;
            }            

            if(curr->next == nullptr) {
                tail = end;
            }
            else {
                end->next = curr->next;
            }            

            delete curr;
            
            curr = end;
            size += X - 1;
        }

        prev = curr;
        curr = curr->next;
    }
}