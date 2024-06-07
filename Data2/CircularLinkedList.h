#pragma once
#include<iostream>
using namespace std;
enum error { underflow, out, success };

struct node
{
	int data;
	node* next;
	node(int d, node* n = 0)
	{
		data = d;	next = n;
	}
};

class list
{
	node* tail;
public:
	list();
	bool is_empty();
	void print();
	void add_end(int el);
	void add_last_begin() {
		if (tail != 0)
		{
			node* tmp = tail;
			do
			{
				if (tmp->next == tail)
				{
					tail = tmp;
					break;
				}
				tmp = tmp->next;
			} while (tmp != tail);
		}
	};
	//.......
	error delete_end();
	error delete_even();
	//.......
	//.......
};

list::list() {
	tail = 0;
}
bool list::is_empty() {
	return tail == 0;
}
void list::print() {
	if (!is_empty())
	{
		node* tmp;
		tmp = tail->next;
		do
		{
			cout << "value is " << tmp->data << endl;
			tmp = tmp->next;
		} while (tmp != tail);
	}
	else
		cout << "not exist" << endl;
}


void list::add_end(int el) {
	if (tail == 0)
		tail = new node(el, tail);
	else
		tail = tail->next = new node(el, tail->next);



}

error list::delete_end() {
	if (!is_empty()) {
		if (tail == tail->next)
		{
			delete tail;
			tail = 0;
		}
		else
		{
			node* t = tail->next;
			for (; t != tail; t = t->next)
			{
				if (t->next == tail)
					break;
			}
			t->next = tail->next;
			delete tail;
			tail = t;
		}

	}
	else {
		return underflow;
	}
}

error list::delete_even() {

	if (tail == 0) {
		return out;
	}
	else {
		node* tmp = tail->next;
		do {
			if (tmp->data % 2 == 0) {
				node* t1 = tmp;
				for (; t1->next != tmp; t1 = t1->next)
					;
				t1->next = tmp->next;
				delete tmp;
			}
			tmp = tmp->next;

		} while (tmp != tail);
	}



}


