#ifndef STRASSEN_H
#define STRASSEN_H

#include <vector>

// Declaración del header para Strassen.
// Se considera que la implementación está en strassen.cpp.
// Contiene la declaración de la función multiplyStrassen 
// para la multiplicación de dos matrices.
std::vector<std::vector<int>> multiplyStrassen(
    std::vector<std::vector<int>>& elementos1,
    std::vector<std::vector<int>>& elementos2
);

#endif // STRASSEN_H