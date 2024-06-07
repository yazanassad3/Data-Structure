#include <iostream>
using namespace std;
enum error{ success, underflow, out};
struct node {
	int data=0;
	node* next;
	node() {
		next = 0;
	}
	node(int el, node *n=0){
		data = el;
		next = n;
	}
};


class list {
	node* h1 = 0, * t1 = 0;
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
	h1 = 0;
	t1 = 0;
};
bool list::is_empty() {
	if (h1 == 0)
		return true;
	else
		return false;
		
}
int list::size(){
	int count = 0;
	for (node* i = h1; i != 0; i = i->next)
		count++;
	return count;
}

void list::add_end(int el) {
	if (h1 == 0) {
		h1 = t1 = new node(el);
	}
	else {
		t1 = t1->next = new node(el);
	}
}

void list::print() {
	for (node* i = h1; i != 0; i = i->next)
		cout << i->data << endl;

}
int main() {
	list l1;
	l1.add_end(15);
	l1.add_end(15);
	l1.add_end(15);
	l1.add_end(15);
	l1.print();
	cout << "add-end"<<endl;
	l1.size();

	return 0;
}