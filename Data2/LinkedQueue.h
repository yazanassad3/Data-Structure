#pragma once
#include<iostream>
using namespace std;


struct node {
	int data;
	node* next;
	node(int d, node* n = 0) {
		data = d;
		next = n;
	}
};

class queue
{
	node* front, * rear;
public:
	queue();
	bool empty();
	void append(int el);
	bool serve();
	bool retrieve(int& el);
	~queue();
};
queue::~queue() {
	node* sto;
	for (node* i = front; i != 0;)
	{
		sto = i;
		if (i != 0)
			i = i->next;
		delete sto;
	}
}

queue::queue() {
	front = rear = 0;
}

bool queue::empty() {
	return  front == 0;
}

void queue::append(int el) {

	if (empty())
	{
		front = rear = new node(el);
	}
	else {
		rear = rear->next = new node(el);
	}
}
bool queue::retrieve(int& el) {

	if (empty())
	{
		return false;
	}
	el = front->data;
	return true;

}