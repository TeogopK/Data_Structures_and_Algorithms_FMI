struct Node{
    int start;
    int end;
    Node* l = nullptr;
    Node* r = nullptr;
};

class MyCalendar {
    Node* head = nullptr;

    bool _book(Node*& head, int start, int end){
        if(!head){
            head = new Node(start, end);

            return true;
        }
        
        if(head->start < start){
            return head->end <= start && _book(head->r, start, end);
        }

        return (head->start > start && head->start >= end) && _book(head->l, start, end);
    }
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        return _book(this->head, startTime, endTime);
    };
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */