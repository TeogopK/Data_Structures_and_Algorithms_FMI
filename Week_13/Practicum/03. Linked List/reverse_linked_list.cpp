#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    int getSize()
    {
        if (!head)
        {
            return 0;
        }

        Node* curr = head;
        int size = 0;
        while (curr)
        {
            curr = curr->next;
            size++;
        }

        return size;
    }


    void reverse(int from, int to) {
        if (!head || from < 1 || to < 1 || from > to)
        {
            return;
        }

        int size = getSize();
        if (from > size)
        {
            return;
        }

        to = min(to, size);

        Node* curr = head;
        int idx = 1;

        Node* lastFromFirst = nullptr;
        while (idx < from)
        {
            lastFromFirst = curr;
            curr = curr->next;
            idx++;
        }

        Node* firstFromSecond = curr;
        Node* prev = nullptr;

        while (idx <= to)
        {
            Node* nextEl = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextEl;
            idx++;
        }

        if (lastFromFirst)
        {
            lastFromFirst->next = prev;
        }

        else
        {
            head = prev;
        }

        firstFromSecond->next = curr;
        if (curr == nullptr)
        {
            tail = firstFromSecond;
        }
    }

    void print() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~List() {
        Node* curr = head;

        while (curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }

        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        string op;
        cin >> op;

        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }

        if (op == "print") {
            testList.print();
        }

        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }

    return 0;
}