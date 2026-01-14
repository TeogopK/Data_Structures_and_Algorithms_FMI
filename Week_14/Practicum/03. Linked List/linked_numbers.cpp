#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node* next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
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
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    Node* head, * tail;
};

void solve(LinkedList& num1, LinkedList& num2) {

    Node* iterNum1 = num1.head;
    Node* iterNum2 = num2.head;

    vector<int> res;
    int carry = 0;
    while (iterNum1 && iterNum2)
    {
        int digit = iterNum1->data + iterNum2->data + carry;
        if (digit >= 10)
        {
            carry = digit / 10;
            digit = digit % 10;
        }

        else
        {
            carry = 0;
        }

        res.push_back(digit);
        iterNum1 = iterNum1->next;
        iterNum2 = iterNum2->next;
    }

    while (iterNum1)
    {
        int digit = iterNum1->data + carry;
        if (digit >= 10)
        {
            carry = digit / 10;
            digit = digit % 10;
        }

        else
        {
            carry = 0;
        }

        res.push_back(digit);
        iterNum1 = iterNum1->next;
    }

    while (iterNum2)
    {
        int digit = iterNum2->data + carry;
        if (digit >= 10)
        {
            carry = digit / 10;
            digit = digit % 10;
        }

        else
        {
            carry = 0;
        }

        res.push_back(digit);
        iterNum2 = iterNum2->next;
    }

    if (carry)
    {
        res.push_back(carry);
    }

    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}