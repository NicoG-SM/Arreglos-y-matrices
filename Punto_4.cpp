#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función que calcula el factorial de un número entero (hasta 10! cabe perfectamente en int)
int calcularFactorial(int num) {
    if (num <= 1) return 1;
    int fact = 1;
    for (int i = 2; i <= num; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    srand(time(nullptr));
    int n;
    cout << "Ingrese un numero entero positivo n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: n debe ser un entero positivo." << endl;
        return 1;
    }

    vector<int> numeros(n);
    cout << "\nNumero -> Factorial\n";
    cout << "-------------------\n";
    for (int i = 0; i < n; ++i) {
        numeros[i] = rand() % 11; // 0 a 10
        cout << "  " << numeros[i] << "!   = " << calcularFactorial(numeros[i]) << "\n";
    }

    return 0;
}