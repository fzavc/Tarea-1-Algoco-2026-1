# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -O2

# Directorios
SRC_DIR = .
ALG_DIR = algorithms
SCRIPT_DIR = scripts

# Archivos fuente
OBJS = sorting.o \
       $(ALG_DIR)/mergesort.o \
	   $(ALG_DIR)/quicksort.o \
       $(ALG_DIR)/sort.o

# Ejecutable
TARGET = sorting
PLOT_SCRIPT = $(SCRIPT_DIR)/plot_generator.py

# Regla principal
all: $(TARGET) run plot

# Link final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilación de sorting.cpp
sorting.o: $(SRC_DIR)/sorting.cpp \
           $(ALG_DIR)/mergesort.h \
		   $(ALG_DIR)/quicksort.h \
           $(ALG_DIR)/sort.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/sorting.cpp

# Compilación de cada archivo en algorithms/
$(ALG_DIR)/mergesort.o: $(ALG_DIR)/mergesort.cpp $(ALG_DIR)/sort.h
	$(CXX) $(CXXFLAGS) -c $(ALG_DIR)/mergesort.cpp -o $(ALG_DIR)/mergesort.o

$(ALG_DIR)/quicksort.o: $(ALG_DIR)/quicksort.cpp $(ALG_DIR)/quicksort.h
	$(CXX) $(CXXFLAGS) -c $(ALG_DIR)/quicksort.cpp -o $(ALG_DIR)/quicksort.o

$(ALG_DIR)/sort.o: $(ALG_DIR)/sort.cpp $(ALG_DIR)/sort.h
	$(CXX) $(CXXFLAGS) -c $(ALG_DIR)/sort.cpp -o $(ALG_DIR)/sort.o

# Ejecutar el programa principal
run: $(TARGET)
	./$(TARGET) data/array_input/10_aleatorio_D1_a.txt

# Ejecutar el script de generación de gráficos
plot: run
	cd $(SCRIPT_DIR) && python3 plot_generator.py

# Limpiar archivos generados
clean:
	rm -f *.o $(ALG_DIR)/*.o $(TARGET)

# Compilar sin ejecutar
build: $(TARGET)

# Ejecutar sin recompilar
run-only: 
	./$(TARGET)
	cd $(SCRIPT_DIR) && python3 plot_generator.py