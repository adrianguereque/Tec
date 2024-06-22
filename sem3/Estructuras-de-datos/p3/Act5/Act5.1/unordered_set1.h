// implementa un tipo de datos para conjuntos utilizando tablas de dispersión
// con función de hashing residual con dirección abierta lineal.
#ifndef UNORDERED_SET1_H
#define UNORDERED_SET1_H

#include <vector>

enum Status {
    empty, 
    erased, 
    occupied
};

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
        vector<int> key;
        vector<Status> flag;
        int size;
};

// Constructor
// Complejidad: O()
unordered_set::unordered_set(int table_size) {
    // COMPLETAR
}

// Agrega un nuevo valor en el conjunto, si no existe.
// Complejidad: O()
void unordered_set::insert(int val) {
    // COMPLETAR
}

// Elimina un valor del conjunto, si existe.
// Complejidad: O()
void unordered_set::erase(int val) {
    // COMPLETAR
}

// determina si un valor pertenece al conjunto.
// Complejidad: O()
bool unordered_set::find(int val) const {
    // COMPLETAR
}

// verifica si el conjunto está vacío.
// Complejidad: O()
bool unordered_set::isEmpty() const {
    return size == 0;
}

// regresa la cantidad de valores en el conjunto.
// Complejidad: O()
int unordered_set::getSize() const {
    return size;
}

// despliega los valores contenidos en el conjunto.
// Complejidad: O()
void unordered_set::print() const
{
    // COMPLETAR
} 

// despliega la tabla de dispersión
// Complejidad: O()
void unordered_set::print_table() const {
    // COMPLETAR
}

#endif //UNORDERED_SET1_H