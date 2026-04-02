/*
Archivo: sorting.cpp

Descripción: Implementa los algoritmos correspondientes, 
para luego recibir como input un arreglo, ordenarlo, 
y guardar los resultados de medición de tiempo y memoria 
en data/measurements.

Bibliografía:
-https://www.geeksforgeeks.org/cpp/chrono-in-c/
-https://en.cppreference.com/w/cpp/chrono.html
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <filesystem>
#include <cmath>

#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/sort.h"

using namespace std;

vector<int> lecturaArchivo(const string& nombre) {
    ifstream fin(nombre);
    vector<int> arreglo;
    int valor;
    if (!fin.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombre << endl;
        return arreglo;
    }
    while (fin >> valor) arreglo.push_back(valor);
    return arreglo;
}

void guardarResultado(const string& archivo, int size, const string& type,
                      const string& domain, char sample,
                      long long tiempo_ns, size_t memoria_bytes) {
    double tiempo_ms = tiempo_ns / 1e6; 
    double tiempo_s  = tiempo_ns / 1e9;

    ofstream fout(archivo, ios::app);
    fout << size << "," << type << "," << domain << "," << sample << ","
         << tiempo_ns << "," << tiempo_ms << "," << tiempo_s << ","
         << memoria_bytes << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <archivo_entrada>" << endl;
        return 1;
    }

    string archivoEntrada = argv[1];
    vector<int> original = lecturaArchivo(archivoEntrada);

    if (original.empty()) {
        cerr << "Archivo no se pudo leer: " << archivoEntrada << endl;
        return 1;
    }

    filesystem::path p(archivoEntrada);
    string nombre = p.stem().string();

    size_t pos1 = nombre.find('_');
    size_t pos2 = nombre.find('_', pos1 + 1);
    size_t pos3 = nombre.find('_', pos2 + 1);

    int n = stoi(nombre.substr(0, pos1));
    string t = nombre.substr(pos1 + 1, pos2 - pos1 - 1);
    string d = nombre.substr(pos2 + 1, pos3 - pos2 - 1);
    char m = nombre.substr(pos3 + 1)[0];

    filesystem::create_directories("data/measurements");

    vector<int> arregloTemporal;
    long long tiempo;
    size_t memoria;

    // Para el algoritmo Merge Sort:
    arregloTemporal = original;
    auto start = chrono::high_resolution_clock::now();
    arregloTemporal = mergeSort(arregloTemporal, 0, arregloTemporal.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // Memoria teórica promedio: O(n)
    memoria = n * sizeof(int);
    guardarResultado("data/measurements/merge_sort.txt", n, t, d, m, tiempo, memoria);

    // Para el algoritmo Quick Sort:
    arregloTemporal = original;
    start = chrono::high_resolution_clock::now();
    arregloTemporal = quickSortMiddle(arregloTemporal, 0, arregloTemporal.size() - 1);
    end = chrono::high_resolution_clock::now();
    tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // Memoria teórica promedio: O(log n)
    memoria = log2(n) * sizeof(int);
    guardarResultado("data/measurements/quick_sort.txt", n, t, d, m, tiempo, memoria);

    // Para el algoritmo Sort:
    arregloTemporal = original;
    start = chrono::high_resolution_clock::now();
    arregloTemporal = sortArray(arregloTemporal);
    end = chrono::high_resolution_clock::now();
    tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // Memoria teórica promedio: O(log n)
    memoria = log2(n) * sizeof(int);
    guardarResultado("data/measurements/sort.txt", n, t, d, m, tiempo, memoria);

    return 0;
}