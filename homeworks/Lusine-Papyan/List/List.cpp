#include <iostream>
#include "List.h"

element::element(int input_data) : prev(NULL), next(NULL), data(input_data) { }
element::element() : prev(NULL), next(NULL) { }

void element::connect(element* element) {
	if (element != NULL) {
		next = element;
		element->prev = this;
	}
}

List::List() : count(0), last(NULL), first(NULL) {}
List::~List() {
	clear();
	}
void List::push_back(const int& d) {
	element* l = new element(d);
	if (last != NULL) {
		last->connect(l);
		last = l;
	}
	else{
		first = last = l;
	}
	++count;
}

void List::show() {
	element* l = first;
	for (int i = 0; i < count; i++) {
		std::cout << l->data << std::endl;
		l = l->next;
	}
}

void List::push_front(const int& data) {
	element* l = new element(data);
	if (first != NULL) {
		l->connect(first);
		first = l;
	}
	else{
		first = last = l;
	}
	++count;
}

void List::insert(const int& data, const int& position) {
	if (position >= count) {
		return;
	}
	element* tmp = new element(d);
	if (first != NULL) {
		if (position == 0) {
			tmp->connect(first);
			first = tmp;
		}
		else {
			element* l = first;
			for (int i = position; i > 0; --i) {
				l = l->next;
			}
			tmp->connect(l->next);
			l->connect(tmp);
		}
	}
	else {
		first = last = tmp;
	}
	++count;
}

void List::pop_front() {
	if (first != NULL) {
		element* l = first;
		if (count == 1) {
			delete first;
			first = NULL;
			last = first;
		}
		else{
			first = first->next;
			first->prev = NULL;
			delete l;
			l = NULL;
		}
		--count;
	}
}

void List::pop_back() {
	if (last != NULL) {
		element* l = last;
		if (count == 1) {
			delete last;
			last = NULL;
			first = last;
		}
		else{
			last = last->prev;
			last->next = NULL;
			delete l;
			l = NULL;
		}
		--count;
	}
}

void List::clear() {
	while (last != NULL) {
		element* l = last;
		last = last->prev;
		delete l;
		l = NULL;
		--count;
	}
	first = NULL;
}

void List::erase(const int& position) {
	if (position >= count || first == NULL) {
		return;
	}
	element* l = first;
	if (position == 0) {
		pop_front();
	}
	else if (position == count - 1) {
		pop_back();
	}
	else{
		l = first;
		for (int i = position; i > 0; --i) {
			l = l->next;
		}
		l->prev->connect(l->next);
		delete l;
		l = NULL;
	}
	--count;
}

int List::size() {
	return count;
}

bool List::empty() {
	return count == 0;
}

int List::front() {
	if (first != NULL) {
		return this->first->data;
	}
}

int List::back() {
	if (last != NULL) {
		return this->last->data;
	}
}
