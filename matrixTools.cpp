#include "matrixTools.h"
#include "simulator_settings.h"

extern char matrix[ROWS][COLUMNS];


void clearMatrix() {
    for (int c = 0; c < COLUMNS; ++c) {
        for (int r = 0; r < ROWS; ++r) {
            matrix[r][c] = false;
        }
    }
	std::cout << "\033[2J\033[H";
}

void drawFrame() {
	extern int sim_ms;
    for (int r = ROWS - 1; r >= 0; --r) {
        if (r < 10) std::cout << '0' << r;
        else std::cout << r;
        std::cout << '|';
        for (int col = 0; col < COLUMNS; ++col) {
            if (matrix[r][col]) std::cout << " " << matrix[r][col] << " ";
            else std::cout << "   ";
        }
        std::cout << "\n";
    }
    std::cout << "   ";
    for (int c = 0; c < COLUMNS; ++c) {
        if (c < 10) std::cout << 0 << c << '|';
        else std::cout << c << '|';
    }
    sim_ms += (int)(1000.0 / FPS);
    std::cout << ">\n" << "Tiempo de simulación: " << ((float)sim_ms / 1000) << "(s) \n";
    usleep((unsigned int)(1000000 / FPS));
}

void addDot(int x, int y, char symbol) {
    if (x >= 0 && x < COLUMNS && y >= 0 && y < ROWS) {
        matrix[y][x] = symbol; 
    }
}

