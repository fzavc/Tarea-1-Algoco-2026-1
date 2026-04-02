# Bibliografia:
# -https://matplotlib.org/2.0.2/users/pyplot_tutorial.html
# -https://www.geeksforgeeks.org/python/os-module-python-examples/
# -https://www.w3schools.com/python/pandas/pandas_getting_started.asp

import os
import pandas as pd
import matplotlib.pyplot as plt

DATA_DIR = "../data/measurements"
PLOT_DIR = "../data/plots"
os.makedirs(PLOT_DIR, exist_ok=True)

algorithms = [
    "naive",
    "strassen"
]

tipos_t = [
    (None, "globales"),
    ("densa", "densas"),
    ("diagonal", "diagonales"),
    ("dispersa", "dispersas"),
]

def generar_grafico(filtro_tipo, nombre_archivo, titulo, columna_y, ylabel):
    plt.figure(figsize=(8,6))
    for algo in algorithms:
        file_path = os.path.join(DATA_DIR, f"{algo}.txt")
        if not os.path.exists(file_path):
            print(f"No se encontró {file_path}, se omite.")
            continue
        
        df = pd.read_csv(file_path)
        
        for col in ["n","caso","tiempo_ns","tiempo_ms","tiempo_s","memoria_bytes"]:
            if col in df.columns:
                df[col] = pd.to_numeric(df[col], errors="coerce")
        
        if filtro_tipo is not None:
            df = df[df["t"] == filtro_tipo]
        
        if df.empty:
            continue
        
        df_grouped = df.groupby("n")[columna_y].mean().reset_index()
        plt.plot(df_grouped["n"], df_grouped[columna_y], marker="o", label=algo.title())
    
    plt.xlabel("Tamaño de la matriz (n x n)")
    plt.ylabel(ylabel)
    plt.title(titulo)
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig(os.path.join(PLOT_DIR, nombre_archivo))
    plt.close()
    print(f"Gráfico guardado en {os.path.join(PLOT_DIR, nombre_archivo)}")

for filtro, nombre in tipos_t:
    generar_grafico(
        filtro,
        f"matrix_tiempo_{'comparacion' if filtro is None else nombre}.png",
        f"Tiempo vs tamaño de la matriz para matrices {nombre}",
        "tiempo_ms",
        "Tiempo de ejecución (ms)"
    )

for filtro, nombre in tipos_t:
    generar_grafico(
        filtro,
        f"matrix_memoria_{'comparacion' if filtro is None else nombre}.png",
        f"Memoria vs tamaño de la matriz para matrices {nombre}",
        "memoria_bytes",
        "Uso de memoria (bytes)"
    )
