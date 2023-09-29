import matplotlib.pyplot as plt
import numpy as np
import time
import random

class Heatmap:
    def __init__(self, file_path=None):
        self.file_path = file_path  # Ruta al archivo
        self.data = None  # Datos
        self.recommended_value = None  # Valor recomendado
        self.fig, self.ax = plt.subplots()  # Crear gráfico
        plt.ion()  # Activar modo interactivo
        self.heatmap = None  # Mapa de calor
        self.colorbar = None  # Barra de color

    def read_data(self):
        if self.file_path:
            with open(self.file_path, 'r') as file:  # Abrir archivo
                lines = file.readlines()  # Leer líneas
                self.data = [float(value) for value in lines[:-1]]  # Convertir a flotante
                self.recommended_value = float(lines[-1])  # Valor recomendado
        else:
            # Simular datos si no hay archivo
            self.data = [random.uniform(20, 80) for _ in range(6)]  # Datos aleatorios
            self.recommended_value = 50.0  # Valor recomendado

    def update(self):
        self.read_data()  # Leer datos
        transposed_data = np.repeat([self.data], 5, axis=0).T  # Transponer datos
        if self.heatmap is None:
            self.heatmap = self.ax.imshow(
                transposed_data,
                cmap='coolwarm', aspect='auto', vmin=0, vmax=100
            )  # Crear mapa de calor
            self.colorbar = plt.colorbar(mappable=self.heatmap, ax=self.ax, orientation='vertical')  # Crear barra de color
        else:
            self.heatmap.set_data(transposed_data)  # Actualizar datos
        self.ax.set_title(f'Valor Recomendado: {self.recommended_value}')  # Título
        plt.draw()  # Dibujar
        plt.pause(1)  # Pausa

    def simulate(self):
        while True:
            self.update()  # Actualizar

if __name__ == "__main__":
    # Si le das la ruta, usa los sensores. Si file_path = None, simula datos.
    heatmap = Heatmap(file_path= "./data.txt")  # Crear mapa de calor
    heatmap.simulate()  # Simular
