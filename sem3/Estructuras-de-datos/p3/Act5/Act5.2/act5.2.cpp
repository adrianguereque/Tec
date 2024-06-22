// Sebastián De Alejandro Villarreal A01285448
// Adrian Guereque A01722394
// Eugenio Garza A00836687
// Maria Ramirez A01753959
// Equipo 7, 29 de noviembre de 2023, Campus Monterrey

// Aplicación para obtener un resumen de intentos de accesos de IPs
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#include "unordered_map.h"

struct Attempts {
  string dirIp;
  int source;
  int target;
};

// convierte una dirección IP en un entero long long que se puede usar como llave del mapa.
long long ip2int(string ip) {
  stringstream ips(ip);
  int p1, p2, p3, p4;
  char c;
  ips >> p1 >> c >> p2 >> c >> p3 >> c >> p4;
  return (long long)(p1 * 1e9 + p2 * 1e6 + p3 * 1e3 + p4);
}

int main() {
  string filename, dummy;
  // cout << "Nombre del archivo? ";
  cin >> filename;

  ifstream bitacora;
  bitacora.open(filename);
  if (!bitacora) {
    cerr << "Error: el archivo " << filename << " no se encontro" << endl;
    return 1;
  }

  int map_size;
  // cout << "# de buckets en el mapa? ";
  cin >> map_size;

  // Mapa de direcciones IP a posiciones en el vector
  unordered_map ip2pos(map_size);
  // lee el # de dirIps y el # de intentos de acceso
  int nips, natts;
  bitacora >> nips >> natts;
  getline(bitacora, dummy);
  // Vector con resumen de intentos de acceso por direcciones IP
  vector<Attempts> attempts(nips);

  // lee las direcciones IP, llena el vector de intentos y el mapa de IPs a posiciones en el vector.
  string dirIp;
  long long key;
  Attempts attempt;
  attempt.source = attempt.target = 0;
  Pair pair;
  
  for (int i = 0; i < nips; i++) {
    bitacora >> dirIp;
    key = ip2int(dirIp);

    attempt.dirIp = dirIp;
    attempts[i] = attempt;

    pair.key = key;
    pair.value = i;
    ip2pos.insert(pair);
  }//Ultima modificación el 29 de noviembre de 2023

  // lee los intentos de acceso y calcula el resumen de intentos para cada dirección IP
  string dirIp1, dirIp2;
  string month, day, hour, error;
  int pos1, pos2;
  for (int i = 0; i < natts; i++) {
    // lee el siguiente intento.
    bitacora >> month >> day >> hour >> dirIp1 >> dirIp2;
    getline(bitacora, error);

    long long sourceKey = ip2int(dirIp1);
    long long destinationKey = ip2int(dirIp2);

    //Encuentra las posiciones de las IPs en el vector de intentos.
    if (ip2pos.find(sourceKey, pos1) && ip2pos.find(destinationKey, pos2)) {
      attempts[pos1].source += 1;
      attempts[pos2].target += 1;
    }
  }//Ultima modificación el 29 de noviembre de 2023

  // realiza N consultas de resúmenes de intentos de accesos.
  int queries;
  // cout << "Cantidad de consultas? ";
  cin >> queries;
  for (int i = 0; i < queries; i++) {
    cin >> dirIp;
    long long queryKey = ip2int(dirIp);
    int pos;

    // Encuentra la posición de la IP en el vector de intentos.
    if (ip2pos.find(queryKey, pos)) {
      cout << "Ip " << i << ": " << dirIp << endl;
      cout << "Intento accesar " << attempts[pos].source << " veces" << endl;
      cout << "Intentaron accesarla " << attempts[pos].target << " veces"
           << endl;
    } else {
      cout << "Ip " << i << ": " << dirIp << " no encontrada" << endl;
    }
    cout << endl;
  } //Ultima modificación el 29 de noviembre de 2023

  return 0;
}
