#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm> // Para std::swap

using namespace std;

// Función auxiliar para imprimir matrices de forma alineada
void imprimirMatriz(const vector<vector<int>>& mat) {
    for (const auto& fila : mat) {
        for (int val : fila) {
            cout << setw(5) << val;
        }
        cout << "\n";
    }
}

int main() {
    int m, n;
    cout << "Ingrese filas (m) y columnas (n): ";
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << "Dimensiones invalidas." << endl;
        return 1;
    }

    vector<vector<int>> matriz(m, vector<int>(n));
    cout << "Ingrese los elementos de la matriz (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    // a) Encontrar máximo y mínimo con sus coordenadas
    int maxVal = matriz[0][0], minVal = matriz[0][0];
    int filaMax = 0, colMax = 0, filaMin = 0, colMin = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] > maxVal) {
                maxVal = matriz[i][j];
                filaMax = i;
                colMax = j;
            }
            if (matriz[i][j] < minVal) {
                minVal = matriz[i][j];
                filaMin = i;
                colMin = j;
            }
        }
    }

    cout << "\na) Elemento maximo: " << maxVal << " en posicion [" << filaMax << "][" << colMax << "]\n";
    cout << "   Elemento minimo: " << minVal << " en posicion [" << filaMin << "][" << colMin << "]\n";

    // b) Intercambiar la fila del máximo con la fila del mínimo
    if (filaMax != filaMin) {
        swap(matriz[filaMax], matriz[filaMin]);
    }

    // c) Calcular la matriz transpuesta (dimensiones n x m) a partir de la matriz modificada
    vector<vector<int>> transpuesta(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    cout << "\nb) Matriz con filas intercambiadas (" << m << "x" << n << "):\n";
    imprimirMatriz(matriz);

    cout << "\nc) Matriz transpuesta (" << n << "x" << m << "):\n";
    imprimirMatriz(transpuesta);

    return 0;
}