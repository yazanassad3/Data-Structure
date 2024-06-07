#pragma once

struct node
{
	int data;
	node* next;
	node(int d, node* n = 0)
	{
		data = d;
		next = n;
	}
};

class stack
{
	node* topp;
public:
	stack();
	void push(int el);
	bool pop();
	int top();
	bool top(int& el);
	~stack();
	void operator=(stack& o);
	stack(stack& o);
};

void stack::push(int el) {
	if (topp == 0) {
		topp = new node(el);
	}
	else {
		topp = new node(el, topp);
	}
}
bool stack::pop() {
	if (topp == 0)
		return false;
	else
	{
		node* t = topp;
		topp = topp->next;
		delete t;
		return true;
	}
}
int stack::top() {
	return topp->data;
}

bool stack::top(int& el) {
	return el == topp->data;
}

stack::~stack() {
	while (topp) {
		delete topp;
		topp = topp->next;
	}
}

void stack::operator=(stack& o) {

	for (node* i = o.topp; i != 0; i = i->next)
		push(i->data);

}