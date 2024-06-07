#pragma once
#include <iostream>
using namespace std;

class queue
{
	int q[5];
	int front, rear, count;
public:
	queue();
	bool empty() { return count == 0; }
	bool full() { return count == 5; }
	bool append(int el);
	bool serve();
	int retrieve();
};
queue::queue() {
	front = 0;
	rear = 4;
	count = 0;
}

bool queue::append(int el) {
	if (full())
		return false;
	else if (rear == 4)
		rear = 0;
	else
		rear++;
	q[rear] = el;
	count++;
	return true;
}

bool queue::serve() {
	if (empty())
		return false;
	else {
		front = front + 1 % 4;
		count++;
		return true;
	}
}

int queue::retrieve() {
	return q[front];
}





