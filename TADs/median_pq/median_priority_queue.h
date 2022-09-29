#pragma once
#include <iostream>
#include <fstream>
#include <queue>

class median_priority_queue
{
protected:
	std::priority_queue<int> menor;
	std::priority_queue<int, std::vector<int>, std::greater<int>> mayor;

	void rebalance();

public:
	median_priority_queue() : menor(), mayor() {}
	void push(int x);
	int top() const;
	void pop();
	int size() const;
	bool empty() const;
};

