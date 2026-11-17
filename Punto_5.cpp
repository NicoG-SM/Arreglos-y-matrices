#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamano n de la matriz cuadrada: ";
    cin >> n;

    if (n <= 0) {
        cout << "Tamano invalido." << endl;
        return 1;
    }

    vector<vector<int>> matriz(n, vector<int>(n));
    cout << "Ingrese los elementos de la matriz (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Asumimos inicialmente que cumple ambas condiciones
    bool esTriangularSuperior = true; // Todos los elementos debajo de la diagonal (i > j) son 0
    bool esTriangularInferior = true; // Todos los elementos encima de la diagonal (i < j) son 0

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j && matriz[i][j] != 0) {
                esTriangularSuperior = false;
            }
            if (i < j && matriz[i][j] != 0) {
                esTriangularInferior = false;
            }
        }
    }

    cout << "\nResultado: ";
    // Si es triangular superior e inferior simultáneamente, es una matriz diagonal
    if (esTriangularSuperior && esTriangularInferior) {
        cout << "La matriz es DIAGONAL (por lo tanto tambien es triangular superior e inferior).\n";
    } else if (esTriangularSuperior) {
        cout << "La matriz es TRIANGULAR SUPERIOR.\n";
    } else if (esTriangularInferior) {
        cout << "La matriz es TRIANGULAR INFERIOR.\n";
    } else {
        cout << "La matriz NO es diagonal ni triangular.\n";
    }

    return 0;
}