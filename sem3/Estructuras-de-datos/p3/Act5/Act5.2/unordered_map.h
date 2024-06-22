// Sebastián De Alejandro Villarreal A01285448
// Adrian Guereque A01722394
// Eugenio Garza A00836687
// Maria Ramirez A01753959
// Equipo 7, 29 de noviembre de 2023, Campus Monterrey

// implementa un tipo de datos para conjuntos utilizando tablas de dispersión con función de hashing residual con encadenamiento externo.
#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <iomanip>
#include <list>
#include <vector>

using namespace std;

struct Pair {
  long long key;
  int value;
};

class unordered_map {
public:
  unordered_map(int table_size);
  void insert(Pair val);
  void erase(long long key);
  bool find(long long key, int &value) const;
  bool isEmpty() const;
  int getSize() const;
  void print() const;

private:
  vector<list<Pair>> map;
  int size;
};

// Constructor. Las variables nuevas y pide el tamaño de la tabla.
// Complejidad: O(1)
unordered_map::unordered_map(int table_size) {
  map.resize(table_size);
  size = 0;
}//Ultima modificación el 29 de noviembre de 2023

// Agrega un nuevo valor en el conjunto, si no existe. Nos pide la variable de val en pares (pair) y nos regresa un nueo valor si es que no existe.
// Complejidad: O(1)
void unordered_map::insert(Pair val) {
  int index = val.key % map.size();
  map[index].push_back(val);
  size++;
}//Ultima modificación el 29 de noviembre de 2023

// Elimina un valor del conjunto, si existe. Nos pide el valor en long long y lo elimina, si no hay nada, pues no pasa nada.
// Complejidad: O(n)
void unordered_map::erase(long long val) {
  int index = val % map.size();

  list<Pair> &bucket = map[index];

  for (auto value = bucket.begin(); value != bucket.end(); value++) {
    if (value->key == val) {
      bucket.erase(value);
      size--;
      return;
    }
  }
}//Ultima modificación el 29 de noviembre de 2023

//Determina si un valor pertenece al conjunto. Nos pide el long long key y variable value en forma constante y nos devuelve si pertenece al conjunto o no.
// Complejidad: O(n)
bool unordered_map::find(long long key, int &value) const {
  int index = key % map.size();

  const list<Pair> &bucket = map[index];

  for (const Pair &pair : bucket) {
    if (pair.key == key) {
      value = pair.value;
      return true;
    }
  }
  return false;
}//Ultima modificación el 29 de noviembre de 2023

//Verifica si el conjunto está vacío. Nos pide el tamaño en constante y si no hay nada, solo marca como 0 o no hay.
// Complejidad: O(1)
bool unordered_map::isEmpty() const {
  return size == 0;
}//Ultima modificación el 29 de noviembre de 2023

//Regresa la cantidad de valores en el conjunto. Nos pide el tamaño en forma constante y nos regresa el tamaño.
// Complejidad: O(1)
int unordered_map::getSize() const { 
  return size; 
}//Ultima modificación el 29 de noviembre de 2023


// Debio desplegar los valores contenidos en el conjunto.
// Complejidad: O(0)
//Debido a que ya se ha imprimido anteriormente todo lo requerido, se hizo algo inutil usarlo
void unordered_map::print() const { // Vacio
}

#endif // UNORDERED_MAP_H
