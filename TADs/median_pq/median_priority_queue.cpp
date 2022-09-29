#include "median_priority_queue.h"

bool median_priority_queue::empty() const{
	return size() == 0;
}

int median_priority_queue::size() const {
	return menor.size() + mayor.size();
}

int median_priority_queue::top() const {
	if(empty())
		throw std::out_of_range("Llamado top en una cola vacia");
	return menor.top();
}

void median_priority_queue::push(int e) {
	if (empty())
		menor.push(e);
	else
	{
		if (e < top()) menor.push(e);
		else mayor.push(e);
		rebalance();
	}
	
}

void median_priority_queue::pop() {
	if (empty())
		throw std::out_of_range("Llamado top en una cola vacia");
	menor.pop();
	rebalance();
}

void median_priority_queue::rebalance() {
	if (menor.size() < mayor.size()) {
		menor.push(mayor.top());
		mayor.pop();
	}
	else if (menor.size() > mayor.size() + 1) {
		mayor.push(menor.top());
		menor.pop();
	}
}