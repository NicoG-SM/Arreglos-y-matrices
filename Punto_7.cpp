#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// d) Función que recibe un arreglo unidimensional (fila) y devuelve la suma de sus elementos
int sumarFila(const vector<int>& fila) {
    int suma = 0;
    for (int val : fila) {
        suma += val;
    }
    return suma;
}

void imprimirMatriz(const vector<vector<int>>& mat, const string& nombre) {
    cout << "\n--- Matriz " << nombre << " ---\n";
    for (const auto& fila : mat) {
        for (int val : fila) {
            cout << setw(6) << val;
        }
        cout << "\n";
    }
}

int main() {
    int m, pA, pB, q;

    // a) Validación de dimensiones para multiplicación matricial (cols A == filas B)
    do {
        cout << "Ingrese dimensiones de matriz A (filas m y columnas p): ";
        cin >> m >> pA;
        cout << "Ingrese dimensiones de matriz B (filas p y columnas q): ";
        cin >> pB >> q;

        if (pA != pB || m <= 0 || pA <= 0 || q <= 0) {
            cout << "Error: El numero de columnas de A (" << pA 
                 << ") debe ser igual al numero de filas de B (" << pB << ") y mayores a 0. Intente de nuevo.\n\n";
        }
    } while (pA != pB || m <= 0 || pA <= 0 || q <= 0);

    int p = pA;
    vector<vector<int>> A(m, vector<int>(p));
    vector<vector<int>> B(p, vector<int>(q));
    vector<vector<int>> C(m, vector<int>(q, 0));

    // b) Llenar ambas matrices
    cout << "\nIngrese los valores de la matriz A (" << m << "x" << p << "):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            cin >> A[i][j];

    cout << "\nIngrese los valores de la matriz B (" << p << "x" << q << "):\n";
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < q; ++j)
            cin >> B[i][j];

    // c) Calcular producto C = A x B
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            for (int k = 0; k < p; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    imprimirMatriz(A, "A");
    imprimirMatriz(B, "B");
    imprimirMatriz(C, "C (A x B)");

    // d) Imprimir la suma de cada fila de C usando la función
    cout << "\nd) Suma de cada fila de la matriz C:\n";
    for (int i = 0; i < m; ++i) {
        cout << "   Fila " << i << ": " << sumarFila(C[i]) << "\n";
    }

    return 0;
}