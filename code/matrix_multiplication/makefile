# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -O2

# Directorios
SRC_DIR = .
ALG_DIR = algorithms
SCRIPT_DIR = scripts

# Archivos fuente
OBJS = matrix_multiplication.o \
       $(ALG_DIR)/naive.o \
       $(ALG_DIR)/strassen.o

# Ejecutable
TARGET = matrix_multiplication
PLOT_SCRIPT = $(SCRIPT_DIR)/plot_generator.py

# Archivos de entrada por defecto
M1 ?= data/matrix_input/16_densa_D0_a_1.txt
M2 ?= data/matrix_input/16_densa_D0_a_1.txt

# Regla principal
all: $(TARGET)

# Link final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilación de matrix_multiplication.cpp
matrix_multiplication.o: $(SRC_DIR)/matrix_multiplication.cpp \
                        $(ALG_DIR)/naive.h \
                        $(ALG_DIR)/strassen.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/matrix_multiplication.cpp

# Compilación de cada archivo en algorithms/
$(ALG_DIR)/naive.o: $(ALG_DIR)/naive.cpp $(ALG_DIR)/naive.h
	$(CXX) $(CXXFLAGS) -c $(ALG_DIR)/naive.cpp -o $(ALG_DIR)/naive.o

$(ALG_DIR)/strassen.o: $(ALG_DIR)/strassen.cpp $(ALG_DIR)/strassen.h
	$(CXX) $(CXXFLAGS) -c $(ALG_DIR)/strassen.cpp -o $(ALG_DIR)/strassen.o

# Ejecutar el programa principal
run: $(TARGET)
	./$(TARGET) $(M1) $(M2)

# Ejecutar el script de generación de gráficos después de run
plot: run
	cd $(SCRIPT_DIR) && python3 plot_generator.py

# Ejecuta todo: compilar + run + plot
all-run: all run plot

# Limpiar archivos generados
clean:
	rm -f *.o $(ALG_DIR)/*.o $(TARGET)

# Compilar sin ejecutar
build: all

# Ejecutar sin recompilar
run-only:
	./$(TARGET) $(M1) $(M2)
	cd $(SCRIPT_DIR) && python3 plot_generator.py
