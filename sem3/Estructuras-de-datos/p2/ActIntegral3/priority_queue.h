#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class priority_queue {
public: // se cambia a que se use con un vector pair de un entero (del cual ordenara el heap)
    priority_queue(); // y un vector (donde se guardaran las ip)
    priority_queue(const vector<pair<int, vector<string>>>& vec); // O(log n)
    void push(int priority, const vector<string>& data); // O(log(n))
    void pop(); // O(log(n))
    pair<int, vector<string>> top() const; // O(1)
    bool empty() const; // O(1)
    int size() const; // O(1)

	// Se le agrega esta funcion para desplegar los 3 conteos mas grandes
	// y sus arreglos
	void displayTop3() const;

private:
    vector<pair<int, vector<string>>> queue;

    // Helper functions
    void rearrange_down(int pos);
    void rearrange_up(int pos);

    friend ostream& operator<<(ostream& out, const priority_queue& heap);
};

priority_queue::priority_queue() {
    // Initialize the queue with a dummy pair
    queue.emplace_back(-1, vector<string>());
}

priority_queue::priority_queue(const vector<pair<int, vector<string>>>& vec) {
    // Initialize the queue with the given vector
    queue = vec;
    queue.insert(queue.begin(), make_pair(-1, vector<string>()));
    for (int pos = queue.size() / 2; pos > 0; pos--)
        rearrange_down(pos);
}

void priority_queue::push(int priority, const vector<string>& data) {
    queue.emplace_back(priority, data);
    rearrange_up(size());
}

void priority_queue::pop() {
    if (!empty()) {
        queue[1] = queue[size()];
        queue.pop_back();
        rearrange_down(1);
    }
}

pair<int, vector<string>> priority_queue::top() const {
    return queue[1];
}

bool priority_queue::empty() const {
    return size() == 0;
}

int priority_queue::size() const {
    return queue.size() - 1;
}

void priority_queue::rearrange_down(int pos) {
    int n = size();
    int child1 = pos * 2;
    if (child1 <= n) {
        int child2 = child1 + 1;
        int max = (queue[child1].first < queue[child2].first) ? child2 : child1;
        if (queue[max].first > queue[pos].first) {
            pair<int, vector<string>> temp = queue[pos];
            queue[pos] = queue[max];
            queue[max] = temp;
            rearrange_down(max);
        }
    }
}

void priority_queue::rearrange_up(int pos) {
    int parent = pos / 2;
    if (parent > 0) {
        if (queue[pos].first > queue[parent].first) {
            pair<int, vector<string>> temp = queue[pos];
            queue[pos] = queue[parent];
            queue[parent] = temp;
            rearrange_up(parent);
        }
    }
}

ostream& operator<<(ostream& out, const priority_queue& heap) {
    for (const auto& value : heap.queue)
        cout << value.first << " ";

    return out;
}

void priority_queue::displayTop3() const {
    int count = 0;
    for (size_t i = 1; i <= size() && count < 3; ++i) {
        cout << "Veces que salen los primeros tres numeros: " << queue[i].first << endl;
		cout<<"IPs: "<<endl;
        for (const auto& val : queue[i].second) {
            cout << val << endl;
        }
        cout << endl;
        ++count;
    }
}

#endif // PRIORITY_QUEUE_H
