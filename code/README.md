# Documentación

## Entrega

La entrega se realiza vía **aula.usm.cl** en formato `.zip`.

## Multiplicación de matrices

En esta sección se implementa la multiplicación de dos matrices de tamaño `N × N`, usando los algoritmos Strassen y Naive.

### Programa principal

- **Archivo:** `code/matrix_multiplication/matrix_multiplication.cpp`
- **Descripción:** Implementa los algoritmos correspondientes, para luego recibir como input dos matrices, multiplicarlas, y guardar los resultados de medición de tiempo y memoria en data/measurements.
- **Ejecución:** Desde la carpeta principal code se debe ejecutar:
  ```bash
  cd matrix_multiplication
  make run
  ```
Con esto se generan los archivos de texto de salida que guardan los resultados de medición de tiempo y memoria en: `code/matrix_multiplication/data/measurements`

### Scripts

En la sección `code/matrix_multiplication/scripts` se incluye herramientas auxiliares para generar datos de prueba, y generar gráficos:

- **`matrix_generator.py`**
  - Genera matrices aleatorias de dimensiones N x N, con N = 16, 64, 256, o 1024, de tipo densas, diagonales o dispersas.
  - Ejecución:
    ```bash
    python3 matrix_generator.py
    ```
- **`plot_generator.py`**
    - Genera gráficos a partir de los datos medidos de tiempo y memoria.
    - Ejecución:
    ```bash
    python3 plot_generator.py
    ```
---

## Ordenamiento de arreglo unidimensional

En esta sección se implementa el ordenamiento de arreglos de tamaño N, usando los algoritmos: MergeSort, QuickSort, std::sort.

### Programa principal

- **Archivo:** `code/sorting/sorting.cpp`
- **Descripción:** Implementa los algoritmos correspondientes, para luego recibir como input un arreglo, ordenarlo, y guardar los resultados de medición de tiempo y memoria en data/measurements.
- **Ejecución:** Desde la carpeta principal code se debe ejecutar:
  ```bash
  cd sorting
  make run
  ```
Con esto se generan los archivos de texto de salida que guardan los resultados de medición de tiempo y memoria en: `code/sorting/data/measurements`

### Scripts

En la sección `code/sorting/scripts` se incluye herramientas auxiliares para generar datos de prueba, y generar gráficos:

- **`array_generator.py`**
  - Genera arreglos aleatorios de tamaño N, con N = 10, 1000, 100000, o 10000000, de tipo aleatorio, ascendentes o descendentes.
  - Ejecución:
    ```bash
    python3 array_generator.py
    ```
- **`plot_generator.py`**
    - Genera gráficos a partir de los datos medidos de tiempo y memoria.
    - Ejecución:
    ```bash
    python3 plot_generator.py
    ```