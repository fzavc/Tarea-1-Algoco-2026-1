// Fuentes:
// Implementacion de algoritmo Merge Sort obtenida de :
// https://www.geeksforgeeks.org/cpp/cpp-program-for-merge-sort/
// Fecha: 23 de Julio de 2025
// Con modificaciones para que funcione mi codigo.

#include <vector>

using namespace std;

// Se funciona dos subarreglos de vec. El primer subarreglo 
// es vec[left..mid]. El segundo es vec[mid+1..right]
void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Se crea vectores temporales
    vector<int> leftVec(n1), rightVec(n2);

    // Se copia los datos a vectores temporales
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Se fusiona vectores temporales nuevamente en vec[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Si hay elementos restantes en leftVec[], se copian.
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Si hay elementos restantes en rightVec[], se copian.
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

// El subarreglo a ordenar está en el rango de indices [left..right]
vector<int> mergeSort(vector<int>& vec, int left, int right) {
// Con modificaciones en tipo de funcion, de void a vector para 
// que retorne el arreglo y funcione mi codigo principal.
    if (left < right) {
      
        // Calcular el punto medio.
        int mid = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad.
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Fusionar las mitades ordenadas.
        merge(vec, left, mid, right);

        return vec;
    }

    return vec;
}