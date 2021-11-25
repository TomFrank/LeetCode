#include "./lttools.cpp"

class Queue {
	//
private:
	int max_size = 1000;
	int arr[max_size];
	int front_idx;
	int back_idx;
public:
	Queue() {
		front_idx = 0;
		back_idx = 0;
	}
	
	enum ErrCode {
		Success,
		EmptyQueue,
		Full
	};
	
	bool isEmpty() {
		return front_idx == back_idx;
	}
	
	bool isFull() {
		return (front_idx + 1) % max_size == back_idx;
	}
	
	int size() {
		return (back_idx - front_idx + max_size) % max_size;
	}
	
	// returns error code
	int front(int& ret) {
		if (isEmpty()) return EmptyQueue;
		ret = arr[front_idx];
		return Success;
	}
	
	void enlarge() {
		int* n = new int[max_size * 2];
		// copy arr to n
		
	}
	
	// returns error code
	int push_back(int x) {
		if (isFull()) {
			
		}
		arr[back_idx] = x;
		back_idx = (back_idx - 1 + max_size) % max_size;
		return Success;
	}
	
	// returns error code
	int pop_front() {
		if (isEmpty()) return EmptyQueue;
		front_idx = (front_idx - 1 + max_size) % max_size;
		return Success;
	}

};

int main(int argc, char *argv[]) {
	
}