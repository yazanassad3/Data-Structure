#pragma once
#include <iostream>
using namespace std;

enum error { success, underflow, out };

struct node
{
	int data;
	node* next;
	node()
	{
		next = 0;
	}
	node(int d, node* n = 0)
	{
		data = d; next = n;
	}
};

class list
{
	node* head, * tail;
public:
	list();
	bool is_empty();
	void print();
	int size();
	void add_begin(int el);
	void add_end(int el);
	error add_pos(int el, int pos);
	void add_sorted(int el);
	error delete_begin();
	error delete_end();
	error delete_pos(int pos);
	error delete_el(int el);
	//bool search(int el);
	int search(int el);
	//node * search(int el);
	~list();
	list(list& o);
	void operator=(list& o);
};
list::list() {
	head = tail = 0;
}
bool list::is_empty() {
	return head == 0;
}

void list::print() {
	if (head != 0)
		for (node* i = head; i != 0; i = i->next)
		{
			cout << "data value = " << i->data << endl;
		}
	else
		cout << "nothing values" << endl;
}

int list::size() {
	int size = 0;
	if (head != 0)
		for (node* i = head; i != 0; i = i->next)
		{
			size++;
		}
	return size;
}


void list::add_begin(int el) {

	if (head == 0)
		head = tail = new node(el);
	else
	{
		head = new node(el, head);
	}
}
void list::add_end(int el) {
	if (head == 0)
		head = tail = new node(el);
	else
		tail = tail->next = new node(el);
}

error list::add_pos(int el, int pos) {
	if (pos > (size() + 1) || pos < 1) {
		return out;
	}
	else {
		if (pos == 1) {
			add_begin(el);
			return success;
		}
		else if (pos == size() + 1)
		{
			add_end(el);
			return success;

		}
		else
		{
			int a = 0;
			for (node* i = head; i != 0; i = i->next)
			{
				if (pos == a) {
					i->next = new node(el, i->next);
				}
				a++;
			}
			return success;
		}
	}

}

void list::add_sorted(int el) {
	node* o;
	o = new node(0);
	if (head == 0) {
		head = tail = new node(el);
	}
	else
		tail = tail->next = new node(el);

	for (node* i = head; i != 0; i = i->next)
	{
		for (node* j = head; j != 0; j = j->next)
		{
			if ((i->data) < (j->data))
			{
				o->data = j->data;
				j->data = i->data;
				i->data = o->data;
			}
		}
	}
}

error list::delete_begin() {
	if (head == 0) {
		return underflow;
	}
	else if (size() == 1) {
		head = tail = 0;
	}
	else {
		node* t = head;
		head = head->next;
		delete t;
	}
	return success;

}

error list::delete_end() {
	if (is_empty())
		return underflow;
	else if (size() == 1) {
		head = tail = 0;
	}
	else {
		node* t = tail;
		for (node* i = head; i != 0; i = i->next)
		{
			if (i->next == tail) {
				tail = i;
				return success;
			}
		}
		delete t;

	}
	return success;
}

int list::search(int el) {
	node* i = head;
	for (int a = 0; a < size(); a++)
	{
		if (i->data == el) {
			return a;
		}
		i = i->next;
	}
	return -1;
}

list::~list() {
	while (!is_empty()) {
		delete_begin();
	}
	cout << "end linked_list statement" << endl;
}



void main() {
	list o;
	o.add_begin(22);
	o.add_end(33);
	o.add_end(3);
	o.add_end(23);
	o.delete_end();
	o.add_end(333);
	o.add_sorted(4);

	o.print();


}