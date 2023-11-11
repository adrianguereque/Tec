#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <fstream>
using namespace std;
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
    queue.push_back(-1);
}

priority_queue::priority_queue(const vector<int> &vec) {
    queue.push_back(-1);
    for(int i=0;i<vec.size();i++){

    }
}

void priority_queue::push(int data) {
    queue.push_back(data);
    rearrange_up(size());
}
void priority_queue::pop() {
    if(!empty()){
        queue[1] = queue[size()];
        queue.pop_back();
        rearrange_down(1);
    }
}

int priority_queue::top() const {
    return queue[1];
}

bool priority_queue::empty() const {
    return size() == 0;
}

int priority_queue::size() const {
    return queue.size() - 1;
}

// funciones de ayuda

void priority_queue::rearrange_down(int pos) {
    int childLeft = pos*2;
    if(childLeft <= size()){
        int childRight = childLeft + 1;
        int max = (queue[childLeft] < queue[childRight]) ? childLeft : childRight;
        if (queue[max] > queue[pos]){
            int temp = queue[pos];
            queue[pos] = queue[max];
            queue[max] = temp;
            rearrange_down(max);
        }
    }
}

void priority_queue::rearrange_up(int pos) {
    int parent = pos/2;
    if(parent>0 && queue[pos]>queue[parent] ){
        int temp = queue[pos];
        queue[pos] = queue[parent];
        queue[parent] = temp;
        rearrange_up(parent);
    }
}

/*ostream &operator<<(ostream &out, const priority_queue &heap) {
    // TO DO
}*/

#endif // PRIORITY_QUEUE_H