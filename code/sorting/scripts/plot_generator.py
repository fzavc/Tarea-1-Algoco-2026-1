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
    "merge_sort",
    "quick_sort",
    "sort",
]

def generar_grafico(filtro_t, nombre_salida, titulo, y_col, y_label):
    plt.figure(figsize=(8, 6))

    for algo in algorithms:
        file_path = os.path.join(DATA_DIR, f"{algo}.txt")
        if not os.path.exists(file_path):
            print(f"No se encontró {file_path}, se omite.")
            continue

        df = pd.read_csv(file_path)

        for col in ["n", "tiempo_ns", "tiempo_ms", "tiempo_s", "memoria_bytes"]:
            if col in df.columns:
                df[col] = pd.to_numeric(df[col], errors="coerce")

        if filtro_t is not None and "t" in df.columns:
            df = df[df["t"] == filtro_t]

        df = df.dropna(subset=["n", y_col])
        df = df.sort_values(by="n")

        if not df.empty:
            plt.plot(df["n"], df[y_col], marker="o", label=algo.replace("_", " ").title())

    plt.xlabel("Tamaño de entrada (n)")
    plt.ylabel(y_label)
    plt.title(titulo)
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    output_path = os.path.join(PLOT_DIR, nombre_salida)
    plt.savefig(output_path)
    plt.close()
    print(f"Gráfico guardado en {output_path}")

casos_t = [
    (None, "globales"),
    ("aleatorio", "aleatorios"),
    ("ascendente", "ascendentes"),
    ("descendente", "descendentes"),
]

for filtro, nombre in casos_t:
    generar_grafico(
        filtro,
        f"sorting_tiempo_{'comparacion' if filtro is None else nombre}.png",
        f"Tiempo vs Tamaño de la entrada para datos {nombre}",
        "tiempo_ms",
        "Tiempo de ejecución (ms)"
    )

for filtro, nombre in casos_t:
    generar_grafico(
        filtro,
        f"sorting_memoria_{'comparacion' if filtro is None else nombre}.png",
        f"Memoria vs Tamaño de la entrada para datos {nombre}",
        "memoria_bytes",
        "Uso de memoria (bytes)"
    )
