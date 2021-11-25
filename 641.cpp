#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

class MyCircularDeque {
public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	
	int* A;
	int k;
	int f;
	int b;
	
	MyCircularDeque(int k) {
		this->k = k + 1;
		A = new int[k+1];
		f = 0;
		b = 0;
	}
	
	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (isFull()) return false;
		f = (f + 1) % k;
		A[f] = value;
		return true;
	}
	
	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (isFull()) return false;
		A[b] = value;
		b = (b - 1 + k) % k;
		return true;
	}
	
	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (isEmpty()) return false;
		f = (f - 1 + k) % k;
		return true;
	}
	
	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (isEmpty()) return false;
		b = (b + 1) % k;
		return true;
	}
	
	/** Get the front item from the deque. */
	int getFront() {
		if (isEmpty()) return -1;
		return A[f];
	}
	
	/** Get the last item from the deque. */
	int getRear() {
		if (isEmpty()) return -1;
		return A[(b + 1) % k];
	}
	
	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return f == b;
	}
	
	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return b == (f + 1) % k;
	}
};

/**
* Your MyCircularDeque object will be instantiated and called as such:
* MyCircularDeque* obj = new MyCircularDeque(k);
* bool param_1 = obj->insertFront(value);
* bool param_2 = obj->insertLast(value);
* bool param_3 = obj->deleteFront();
* bool param_4 = obj->deleteLast();
* int param_5 = obj->getFront();
* int param_6 = obj->getRear();
* bool param_7 = obj->isEmpty();
* bool param_8 = obj->isFull();
*/

int main(int argc, char *argv[]) {
	
}