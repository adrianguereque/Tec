// Eugenio Garza A00836687
// Descripcion: Un programa que utiliza un arbol con diferntes funciones a realizar. Simula una fila priorizada de enteros con prioridad de valor mayor
// Ultima modificacion: 12 Oct 2023

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>


class priority_queue {
    public:
        priority_queue();
        priority_queue(const vector<int> &vec);// O(log n)
        void push(int data); //O(log(n))
        void pop(); //O(log(n))
        int top() const; //O(1)
        bool empty() const; //O(1)
        int size() const; //O(1)

    private:
        vector<int> queue;
        // funciones de ayuda
        void rearrange_down(int pos);
        void rearrange_up(int pos);

        friend ostream &operator<<(ostream &out, const priority_queue &heap);
};

priority_queue::priority_queue() { // el vector va a contner los datos del heap pero la primera posicion lleva un -1
    queue.push_back(-1); 
}

priority_queue::priority_queue(const vector<int> &vec) {
	queue = vec;
	queue.insert(queue.begin(), -1);
	for (int pos = queue.size() / 2; pos > 0; pos--)
		rearrange_down(pos);
}

void priority_queue::push(int data) { // Empuja un elemento
    queue.push_back(data);
	rearrange_up(size());
}

void priority_queue::pop() { // Elimina un elemento
    if (! empty()) {
		queue[1] = queue[size()];
		queue.pop_back();
		rearrange_down(1); // 1 porq la raiz siempre esta en la posicion 1
	}
}

int priority_queue::top() const { // donde esta el elemento superior, la raiz
    return queue[1];
}

bool priority_queue::empty() const { // hace que el tamaño sea 0
    return size() == 0;
}

int priority_queue::size() const { // Da el tamaño del priority queue
    return queue.size() - 1;
}

// funciones de ayuda

void priority_queue::rearrange_down(int pos) { //intercambia posiciones entre dos childs
    int n = size();
	int child1 = pos * 2; // asi me da la posicion del hijo 1
	if (child1 <= n) {
		int child2 = child1 + 1;
		int max = (queue[child1] < queue[child2]) ? child2 : child1;
		if (queue[max] > queue[pos]) {
			int temp = queue[pos];
			queue[pos] = queue[max];
			queue[max] = temp;
			rearrange_down(max);
		}
	}
}// O(log N)

void priority_queue::rearrange_up(int pos) { //intercambia posiciones entre padre e hijo
    int parent = pos / 2; // Asi me da la posicion del padre
	if (parent > 0) {
		if (queue[pos] > queue[parent]) { // si el hijo es mayor que el padre
			int temp = queue[pos]; //proceso para hacer el intercambio de posicion
			queue[pos] = queue[parent];
			queue[parent] = temp;
			rearrange_up(parent);
		}
	}
}// O(log N)

ostream &operator<<(ostream &out, const priority_queue &heap) {
	for (auto value : heap.queue)
		cout << value << " ";
	
	return out;
}// )(n)

#endif // PRIORITY_QUEUE_H