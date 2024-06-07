#pragma once
#include<iostream>
using namespace std;

enum errorcode { success, underflaw, out };



class Node {
public:
    Node(const int el, Node* n = 0, Node* p = 0) {
        info = el; next = n; prev = p;
    }
    int info;
    Node* next, * prev;
};


class DoublyLinkedList {
private:
    Node* head, * tail;
public:
    DoublyLinkedList();
    bool isEmpty();
    int size();
    void print();
    void print_b();
    void addToDLLTail(int el);
    errorcode deleteFromDLLTail();
    void addToDLLHead(int el);
    errorcode deleteFromDLLHead();
    errorcode addToPos(int el, int pos);
    errorcode deleteFromPos(int pos);
    errorcode AddFirstValueCount();
    int LastOddElement();
    ~DoublyLinkedList();
    //void operator=(DoublyLinkedList<T>&o);
    //DoublyLinkedList(DoublyLinkedList<T>&o);

};
int DoublyLinkedList::LastOddElement() {
    if (tail != 0)
    {
        int count = 0;
        Node* o = tail;
        do {

            if (o->info % 2 == 1) {
                Node* s = tail->next;
                do {
                    if (s == o)
                        return count;
                    count++;
                    s = s->next;
                } while (s->next);

            }
            o = o->prev;
        } while (o->prev);

    }





}


DoublyLinkedList::~DoublyLinkedList() {

    Node* tmp;
    while (tail != 0) {
        tmp = tail;
        tail = tail->prev;
        delete tmp;
    }

    cout << "end Doply list" << endl;
}
errorcode DoublyLinkedList::AddFirstValueCount() {
    if (tail != 0)
    {
        int count = 0;
        Node* o = tail;
        for (; o->prev != 0; o = o->prev) {
        }
        Node* o2 = o;
        for (; o2->next != 0; o2 = o2->next) {
            if (o->info == o2->info)
                count++;
        }
        head = head->prev = new Node(count, head);




    }
    return success;
}





DoublyLinkedList::DoublyLinkedList() {
    head = tail = 0;
}


bool DoublyLinkedList::isEmpty() {
    if (head == 0)
    {
        return true;
    }
    else
        return false;

}

int DoublyLinkedList::size() {
    int count = 0;
    for (Node* i = head; i != 0; i = i->next)
    {
        count++;
    }
    return count;
}
void DoublyLinkedList::print() {
    for (Node* i = head; i != 0; i = i->next)
    {
        cout << "n =" << i->info << endl;
    }

}
void DoublyLinkedList::print_b() {
    for (Node* i = tail; i != 0; i = i->prev)
    {
        cout << "n =" << i->info << endl;
    }

}
void DoublyLinkedList::addToDLLTail(int el) {
    if (tail != 0)
    {
        tail = new Node(el, 0, tail);
        tail->prev->next = tail;
    }
    else
        head = tail = new Node(el);

}
void DoublyLinkedList::addToDLLHead(int el) {
    if (head != 0) {
        head = head->prev = new Node(el, head, 0);
    }
    else
        head = tail = new Node(el);
}
errorcode DoublyLinkedList::deleteFromDLLTail() {
    if (head == 0)
        return out;
    else if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }



}
errorcode DoublyLinkedList::deleteFromDLLHead() {
    if (head == 0)
        return underflaw;
    else if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else {
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
}