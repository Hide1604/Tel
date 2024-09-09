#include <iostream>
#include <vector>

const int ANCHO = 41;  // Ancho del eje x (de 0 a 20)
const int ALTO = 21; // Alto del eje y (de 0 a 30)

// Función para imprimir el plano de coordenadas con múltiples puntos
void printGrid(const std::vector<std::pair<int, int>>& points) {
    // Crear una matriz que representa el plano de coordenadas
    char grid[ALTO][ANCHO];
    
    // Inicializar la matriz con espacios
    for (int y = 0; y < ALTO; ++y) {
        for (int x = 0; x < ANCHO; ++x) {
            grid[y][x] = ' ';
        }
    }

    // Dibujar los ejes
    // Eje x (horizontal) en la última fila
    for (int x = 0; x < ANCHO; ++x) {
        grid[ALTO - 1][x] = '-';
    }

    // Eje y (vertical) en la primera columna
    for (int y = 0; y < ALTO; ++y) {
        grid[y][0] = '|';
    }

    // Esquina (0, 0)
    grid[ALTO - 1][0] = '+';

    // Marcar las coordenadas
    for (const auto& point : points) {
        int markX = point.first;
        int markY = point.second;

        if (markX >= 0 && markX < ANCHO && markY >= 0 && markY < ALTO) {
            if (markX == 0 && markY == 0) {
                grid[ALTO - 1][0] = '*'; // Sobrescribir el '+' con '*'
            } else {
                grid[ALTO - markY - 1][markX] = '*'; // Marcar con '*'
            }
        }
    }

    // Imprimir la matriz
    for (int y = 0; y < ALTO; ++y) { // Imprimir desde el borde superior hacia abajo
        for (int x = 0; x < ANCHO; ++x) {
            std::cout << grid[y][x];
        }
        std::cout << std::endl;
    }
}

int main() {
    int numPoints;

    // Solicitar al usuario la cantidad de puntos
    std::cout << "Ingrese el número de puntos: ";
    std::cin >> numPoints;

    // Verificar que el número de puntos sea válido
    if (numPoints <= 0) {
        std::cerr << "Número de puntos inválido." << std::endl;
        return 1;
    }

    // Leer las coordenadas de los puntos
    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < numPoints; ++i) {
        int x, y;
        std::cout << "Ingrese la coordenada X para el punto " << i + 1 << " (0-20): ";
        std::cin >> x;
        std::cout << "Ingrese la coordenada Y para el punto " << i + 1 << " (0-30): ";
        std::cin >> y;

        // Validar las coordenadas ingresadas
        if (x < 0 || x >= ANCHO || y < 0 || y >= ALTO) {
            std::cerr << "Coordenadas fuera de rango. Por favor, ingrese valores válidos." << std::endl;
            return 1;
        }

        points.emplace_back(x, y);
    }

    // Imprimir el plano con los puntos marcados
    printGrid(points);

    return 0;
}
