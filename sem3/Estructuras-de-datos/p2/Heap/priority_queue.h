#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>

class priority_queue {
    public:
        priority_queue();
        priority_queue(const vector<int> &vec);
        void push(int data);
        void pop();
        int top() const;
        bool empty() const;
        int size() const;

    private:
        vector<int> queue;
        // funciones de ayuda
        void rearrange_down(int pos);
        void rearrange_up(int pos);

        friend ostream &operator<<(ostream &out, const priority_queue &heap);
};

priority_queue::priority_queue() {
    // TO DO
}

priority_queue::priority_queue(const vector<int> &vec) {
    // TO DO
}

void priority_queue::push(int data) {
    // TO DO
}

void priority_queue::pop() {
    // TO DO
}

int priority_queue::top() const {
    // TO DO
}

bool priority_queue::empty() const {
    // TO DO
}

int priority_queue::size() const {
    // TO DO
}

// funciones de ayuda

void priority_queue::rearrange_down(int pos) {
    // TO DO
}

void priority_queue::rearrange_up(int pos) {
    // TO DO
}

ostream &operator<<(ostream &out, const priority_queue &heap) {
    // TO DO
}

#endif // PRIORITY_QUEUE_H