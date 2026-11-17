#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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

    // Llenar el vector con aleatorios entre 0 y 10 y acumular la suma
    cout << "Vector generado: ";
    for (int i = 0; i < n; ++i) {
        numeros[i] = rand() % 11; // 0 a 10
        suma += numeros[i];
        cout << numeros[i] << " ";
    }
    cout << "\n";

    // Calcular la media
    double media = suma / n;
    cout << "Media de los elementos: " << fixed << setprecision(2) << media << "\n";

    // Segundo vector para almacenar elementos estrictamente mayores que la media
    vector<int> mayoresMedia;
    for (int num : numeros) {
        if (num > media) {
            mayoresMedia.push_back(num);
        }
    }

    cout << "Elementos mayores que la media: ";
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