#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

class unordered_set {
public:
    unordered_set(int table_size);
    void insert(int val);
    void erase(int val);
    bool find(int val) const;
    bool isEmpty() const;
    int getSize() const;
    void print() const;
    void print_table() const;

private:
    std::vector<std::list<int>> table;
    int size;
    int hash(int val) const;
};

// Constructor
unordered_set::unordered_set(int table_size) : table(table_size), size(0) {
    // Initialize the hash table with empty lists
}

// Hash function
int unordered_set::hash(int val) const {
    // Use a simple hash function for demonstration purposes
    return val % table.size();
}

// Agrega un nuevo valor en el conjunto, si no existe.
void unordered_set::insert(int val) {
    int index = hash(val);
    auto& bucket = table[index];

    // Check if the value already exists in the set
    if (std::find(bucket.begin(), bucket.end(), val) == bucket.end()) {
        // Value not found, insert it
        bucket.push_back(val);
        size++;
    }
}

// Elimina un valor del conjunto, si existe.
void unordered_set::erase(int val) {
    int index = hash(val);
    auto& bucket = table[index];

    // Find the value in the list and remove it
    bucket.remove(val);
}

// determina si un valor pertenece al conjunto.
bool unordered_set::find(int val) const {
    int index = hash(val);
    const auto& bucket = table[index];

    // Check if the value is in the list
    return std::find(bucket.begin(), bucket.end(), val) != bucket.end();
}

// verifica si el conjunto está vacío.
bool unordered_set::isEmpty() const {
    return size == 0;
}

// regresa la cantidad de valores en el conjunto.
int unordered_set::getSize() const {
    return size;
}

// despliega los valores contenidos en el conjunto.
void unordered_set::print() const {
    for (const auto& bucket : table) {
        for (int val : bucket) {
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
}

// despliega la tabla de dispersión
void unordered_set::print_table() const {
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << "[" << i << "]: ";
        for (int val : table[i]) {
            std::cout << "-> " << val << " ";
        }
        std::cout << std::endl;
    }
}
