#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm> // Para std::sort

using namespace std;

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
    double suma = 0;

    cout << "Vector generado: ";
    for (int i = 0; i < n; ++i) {
        numeros[i] = rand() % 11;
        suma += numeros[i];
        cout << numeros[i] << " ";
    }
    cout << "\n";

    double media = suma / n;
    cout << "Media de los elementos: " << fixed << setprecision(2) << media << "\n";

    vector<int> mayoresMedia;
    for (int num : numeros) {
        if (num > media) {
            mayoresMedia.push_back(num);
        }
    }

    // Ordenar de menor a mayor utilizando sort de la biblioteca estándar
    sort(mayoresMedia.begin(), mayoresMedia.end());

    cout << "Elementos mayores que la media (ordenados de menor a mayor): ";
    if (mayoresMedia.empty()) {
        cout << "Ninguno";
    } else {
        for (int num : mayoresMedia) {
            cout << num << " ";
        }
    }
    cout << "\n";

    return 0;
}