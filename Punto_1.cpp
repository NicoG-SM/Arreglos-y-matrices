#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

// Función auxiliar para determinar si un número es primo
bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    srand(time(nullptr));
    int n;
    cout << "Ingrese el tamano n de la matriz cuadrada: ";
    cin >> n;

    if (n <= 0) {
        cout << "El tamano debe ser positivo." << endl;
        return 1;
    }

    // a) Generar matriz n x n con valores aleatorios entre 0 y 50
    vector<vector<int>> matriz(n, vector<int>(n));
    cout << "\n--- Matriz Generada (" << n << "x" << n << ") ---\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 51; // 0 a 50
            cout << setw(4) << matriz[i][j];
        }
        cout << "\n";
    }

    // b) Extraer diagonales principal y secundaria, y hallar la suma de sus elementos
    vector<int> diagPrincipal(n), diagSecundaria(n);
    int sumaPrincipal = 0, sumaSecundaria = 0;
    for (int i = 0; i < n; ++i) {
        diagPrincipal[i] = matriz[i][i];
        diagSecundaria[i] = matriz[i][n - 1 - i];
        sumaPrincipal += diagPrincipal[i];
        sumaSecundaria += diagSecundaria[i];
    }
    cout << "\nb) Diagonal Principal: ";
    for (int x : diagPrincipal) cout << x << " ";
    cout << "| Suma: " << sumaPrincipal << "\n";

    cout << "   Diagonal Secundaria: ";
    for (int x : diagSecundaria) cout << x << " ";
    cout << "| Suma: " << sumaSecundaria << "\n";

    // c) Primera fila y última columna -> elevar al cuadrado -> sumar posición a posición
    vector<int> primeraFila(n), ultimaColumna(n), sumaCuadrados(n);
    for (int i = 0; i < n; ++i) {
        primeraFila[i] = matriz[0][i];
        ultimaColumna[i] = matriz[i][n - 1];
        sumaCuadrados[i] = (primeraFila[i] * primeraFila[i]) + (ultimaColumna[i] * ultimaColumna[i]);
    }
    cout << "\nc) Vector suma de cuadrados (1ra fila^2 + ultima col^2): ";
    for (int x : sumaCuadrados) cout << x << " ";
    cout << "\n";

    // d) y e) Contar primos, pares, impares y divisibles por 3
    int contPrimos = 0, contPares = 0, contImpares = 0, contDiv3 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = matriz[i][j];
            if (esPrimo(val)) contPrimos++;
            if (val % 2 == 0) contPares++;
            else contImpares++;
            if (val % 3 == 0) contDiv3++;
        }
    }
    cout << "\nd) Cantidad de numeros primos: " << contPrimos << "\n";
    cout << "e) Pares: " << contPares << " | Impares: " << contImpares 
         << " | Divisibles por 3: " << contDiv3 << "\n";

    // f) Suma por columnas, conversión a radianes y cálculo de seno
    vector<int> sumaColumnas(n, 0);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            sumaColumnas[j] += matriz[i][j];
        }
    }
    const double PI = acos(-1.0); // Uso de <cmath> para obtener PI
    cout << "\nf) Tabla Suma de Columnas (Grados) vs Seno (Radianes):\n";
    cout << setw(15) << "Eje X (Suma)" << " | " << setw(15) << "Eje Y (Seno)" << "\n";
    cout << "-----------------------------------\n";
    for (int j = 0; j < n; ++j) {
        double radianes = sumaColumnas[j] * (PI / 180.0);
        double seno = sin(radianes);
        cout << setw(15) << sumaColumnas[j] << " | " << setw(15) << fixed << setprecision(4) << seno << "\n";
    }

    // g) Aplanar matriz a 1D, calcular promedio y dividir cada elemento por el promedio
    vector<int> vector1D;
    double sumaTotal = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector1D.push_back(matriz[i][j]);
            sumaTotal += matriz[i][j];
        }
    }
    double promedio = sumaTotal / (n * n);
    cout << "\ng) Promedio general: " << fixed << setprecision(2) << promedio << "\n";
    cout << "   Elementos divididos por el promedio:\n   ";
    for (int val : vector1D) {
        if (promedio != 0)
            cout << fixed << setprecision(2) << (val / promedio) << " ";
        else
            cout << "0.00 ";
    }
    cout << "\n";

    return 0;
}