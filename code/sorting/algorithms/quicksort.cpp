// Fuentes:
// Para la implementacion del algoritmo Quick Sort se elige 
// la variacion Middle Element, la cual es obtenida de:
// https://stackoverflow.com/questions/33837737/quick-sort-middle-pivot-implementation-strange-behaviour
// Codigo compartido por el usuario "rcgldr".
// Fecha: 20 de Noviembre de 2015.
// Con modificaciones para que funcione mi codigo.

#include <vector>
#include <algorithm>

using namespace std;

// Con modificaciones en tipo de funcion, de void a vector para 
// que retorne el arreglo y funcione mi codigo principal.
vector<int> quickSortMiddle(vector<int> &a, int left, int right) {
    if(left >=right) return a;
    int leftI = left;
    int rightI = right;
    int pivot = a[left + (right - left)/2]; // set pivot to value
    while(leftI<=rightI) {
        while(a[leftI]  < pivot )leftI++;   // use pivot by value
        while(a[rightI] > pivot )rightI--;  // use pivot by value
        if(leftI <=rightI)
        {
            swap(a[leftI], a[rightI]);
            leftI++;
            rightI--;
        }
    }
    if(left < rightI)quickSortMiddle(a,left,rightI);
    if(leftI < right)quickSortMiddle(a,leftI,right); 

    return a;
}