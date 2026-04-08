/*
Archivo: matrix_multiplication.cpp

Descripción: Implementa los algoritmos correspondientes, 
para luego recibir como input dos matrices, multiplicarlas, 
y guardar los resultados de medición de tiempo y memoria 
en data/measurements.

Bibliografía:
-https://www.geeksforgeeks.org/cpp/chrono-in-c/
-https://en.cppreference.com/w/cpp/chrono.html

Autora: Francisca Zavala Cortés, rol 202173632-8
Tarea 1 Algoritmos y Complejidad 2026-1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <filesystem>

#include "algorithms/naive.h"
#include "algorithms/strassen.h"

using namespace std;

vector<vector<int>> lecturaArchivo(const string& nombre) {
    ifstream fin(nombre);
    vector<vector<int>> matriz;
    string linea;
    if (!fin.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombre << endl;
        return matriz;
    }
    while (getline(fin, linea)) {
        if (linea.empty()) continue;
        istringstream iss(linea);
        vector<int> fila;
        int valor;
        while (iss >> valor) fila.push_back(valor);
        matriz.push_back(fila);
    }
    return matriz;
}

void guardarResultado(const string& archivo, int n, const string& t, const string& d,
                      char m, int caso, long long tiempo_ns, size_t memoria_bytes) {
    double tiempo_ms = tiempo_ns / 1'000'000.0;
    double tiempo_s  = tiempo_ns / 1'000'000'000.0;

    ofstream fout(archivo, ios::app);
    fout << n << "," << t << "," << d << "," << m << "," << caso << ","
         << tiempo_ns << "," << tiempo_ms << "," << tiempo_s << "," 
         << memoria_bytes << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Uso: " << argv[0] << " <matriz1.txt> <matriz2.txt>" << endl;
        return 1;
    }

    string archivoM1 = argv[1];
    string archivoM2 = argv[2];

    vector<vector<int>> matriz1 = lecturaArchivo(archivoM1);
    vector<vector<int>> matriz2 = lecturaArchivo(archivoM2);

    if (matriz1.empty() || matriz2.empty()) {
        cerr << "Error: No se pudo leer las matrices." << endl;
        return 1;
    }

    filesystem::path p(archivoM1);
    string nombre = p.stem().string(); 

    int n, caso;
    string t, d;
    char m;

    istringstream iss(nombre);
    string temp;
    getline(iss, temp, '_'); n = stoi(temp);
    getline(iss, t, '_');
    getline(iss, d, '_');
    getline(iss, temp, '_'); m = temp[0];
    getline(iss, temp, '_'); caso = stoi(temp);

    filesystem::create_directories("data/measurements");

    vector<vector<int>> resultado;
    long long tiempo;
    size_t memoria;

    // Para el algoritmo Naive:
    auto start = chrono::high_resolution_clock::now();
    resultado = multiplyNaive(matriz1, matriz2);
    auto end = chrono::high_resolution_clock::now();
    tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // Memoria teórica promedio: O(n^2)
    memoria = n * n * sizeof(int);
    guardarResultado("data/measurements/naive.txt", n, t, d, m, caso, tiempo, memoria);

    // Para el algoritmo Strassen:
    start = chrono::high_resolution_clock::now();
    resultado = multiplyStrassen(matriz1, matriz2);
    end = chrono::high_resolution_clock::now();
    tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // Memoria teórica promedio: O(n^2)
    memoria = n * n * sizeof(int);
    guardarResultado("data/measurements/strassen.txt", n, t, d, m, caso, tiempo, memoria);

    return 0;
}
