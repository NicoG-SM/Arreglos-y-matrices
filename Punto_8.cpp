#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cout << "Ingrese el numero de estudiantes (n): ";
    cin >> n;
    cout << "Ingrese el numero de asignaturas (m): ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Cantidad invalida." << endl;
        return 1;
    }

    // a) Matriz de calificaciones n x m validando rango [0.0, 5.0]
    vector<vector<double>> notas(n, vector<double>(m));
    for (int i = 0; i < n; ++i) {
        cout << "\n--- Estudiante " << i << " ---\n";
        for (int j = 0; j < m; ++j) {
            double nota;
            do {
                cout << "Nota asignatura " << j << " (0.0 - 5.0): ";
                cin >> nota;
                if (nota < 0.0 || nota > 5.0) {
                    cout << "Error: La calificacion debe estar entre 0.0 y 5.0.\n";
                }
            } while (nota < 0.0 || nota > 5.0);
            notas[i][j] = nota;
        }
    }

    // b) Promedio de cada estudiante (por filas)
    vector<double> promEstudiantes(n, 0.0);
    for (int i = 0; i < n; ++i) {
        double suma = 0.0;
        for (int j = 0; j < m; ++j) {
            suma += notas[i][j];
        }
        promEstudiantes[i] = suma / m;
    }

    // c) Promedio de cada asignatura (por columnas)
    vector<double> promAsignaturas(m, 0.0);
    for (int j = 0; j < m; ++j) {
        double suma = 0.0;
        for (int i = 0; i < n; ++i) {
            suma += notas[i][j];
        }
        promAsignaturas[j] = suma / n;
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Promedio por Estudiante ---\n";
    for (int i = 0; i < n; ++i) {
        cout << "Estudiante [" << i << "]: " << promEstudiantes[i] << "\n";
    }

    cout << "\n--- Promedio por Asignatura ---\n";
    for (int j = 0; j < m; ++j) {
        cout << "Asignatura [" << j << "]: " << promAsignaturas[j] << "\n";
    }

    // d) Estudiante con promedio más alto y asignatura con promedio más bajo
    int idxMejorEst = 0;
    for (int i = 1; i < n; ++i) {
        if (promEstudiantes[i] > promEstudiantes[idxMejorEst]) {
            idxMejorEst = i;
        }
    }

    int idxPeorAsig = 0;
    for (int j = 1; j < m; ++j) {
        if (promAsignaturas[j] < promAsignaturas[idxPeorAsig]) {
            idxPeorAsig = j;
        }
    }

    cout << "\n--- Resultados Destacados ---\n";
    cout << "Estudiante con promedio mas alto: Indice " << idxMejorEst 
         << " (Promedio: " << promEstudiantes[idxMejorEst] << ")\n";
    cout << "Asignatura con promedio mas bajo: Indice " << idxPeorAsig 
         << " (Promedio: " << promAsignaturas[idxPeorAsig] << ")\n";

    return 0;
}