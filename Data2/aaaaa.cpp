/*#include <iostream>
using namespace std;

enum error { success, underflow, out };
struct node {
	int data = 0;
	node*next;
	node() {
		next = 0;
	}
	node(int el, node* n = 0) {
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
	
	//void add_sorted(int el);
	void delete_begin();
	//error delete_end();
	void delete_pos(int pos);
	//error delete_el(int el);
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
void list::delete_pos(int pos) {
	if (pos<1 || pos>size())
		cout << " ";
	else {
		int count = 0;
		for (node *i = h1; i !=0 ; i->next )
		{
			if (count == pos-1)
			{
				node* t,*j;
				
				t = i->next;
				j = t->next;
				delete t;
				i->next = j;

			}
			count++;

		}
	
	}



}
void list::delete_begin() {
	if (size()==1)
	{	
		delete h1;
		h1=t1= t1->next;

	}
	else {
		node *t;
		t = h1;
		h1 = h1->next;
		delete t;
	
	
	}




}

void list::add_begin(int el) {
	if (is_empty())
		h1 = t1 = new node(el);
	else
		h1 = new node(el, h1);
}

bool list::is_empty() {
	if (h1 == 0)
		return true;
	else
		return false;

}
int list::size() {
	int count = 0;
	for (node* i = h1; i != 0; i = i->next)
		count++;
	return count;
}
error list::add_pos(int el, int pos) {
	int count = 0;
	if (size() < pos || pos < 0)
		return out;
	else if	(is_empty()) {
		h1 = t1 = new node(el);
		return success;
	}
	else {
		for (node* i = h1; i != 0; i = i->next) {
			if (count == pos - 1)
			{
				i->next = new node(el, i->next);
			}
			count++;
		}
		return success;
	}

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
	l1.add_end(13);
	l1.add_end(11);
	l1.add_end(7);
	l1.add_begin(25);
	l1.add_pos(12,3 );
	l1.delete_begin();
	l1.delete_pos(2);
	l1.print();

	cout << "add-end" << endl;
	cout<<l1.size();
	return 0;
}*/