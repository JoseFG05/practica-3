#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Para calcular distancia

using namespace std;

// Estructura para representar una coordenada
struct Coordenada {
    double x;
    double y;
};

// Función para determinar el cuadrante de una coordenada
string determinarCuadrante(const Coordenada &coord) {
    if (coord.x > 0 && coord.y > 0) return "Cuadrante I";
    if (coord.x < 0 && coord.y > 0) return "Cuadrante II";
    if (coord.x < 0 && coord.y < 0) return "Cuadrante III";
    if (coord.x > 0 && coord.y < 0) return "Cuadrante IV";
    if (coord.x == 0 && coord.y != 0) return "Eje Y";
    if (coord.y == 0 && coord.x != 0) return "Eje X";
    return "Origen";
}

// Función para calcular la ecuación de la recta entre dos puntos
string calcularEcuacionRecta(const Coordenada &p1, const Coordenada &p2) {
    if (p1.x == p2.x) return "x = " + to_string(p1.x); // Recta vertical
    double m = (p2.y - p1.y) / (p2.x - p1.x);           // Pendiente
    double b = p1.y - m * p1.x;                         // Intersección
    return "y = " + to_string(m) + "x + " + to_string(b);
}

// Función principal
int main() {
    int n;
    cout << "Ingrese el numero de coordenadas: ";
    cin >> n;

    vector<Coordenada> coordenadas(n);

    // Leer coordenadas
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la coordenada " << i + 1 << " (x y): ";
        cin >> coordenadas[i].x >> coordenadas[i].y;
    }

    // Mostrar cuadrantes
    cout << "\nCuadrantes de las coordenadas:\n";
    for (const auto& coordenadas : coordenadas){
        cout << "(" << coordenadas.x << ", " << coordenadas.y << ") -> " << determinarCuadrante(coordenadas) << endl;
    }

    // Verificar rectas entre cada par de puntos
    cout << "\nEcuaciones de rectas entre pares de puntos:\n";
    for (size_t i = 0; i < coordenadas.size(); i++) {
        for (size_t j = i + 1; j < coordenadas.size(); j++) {
            cout << "Entre (" << coordenadas[i].x << ", " << coordenadas[i].y << ") y ("
                 << coordenadas[j].x << ", " << coordenadas[j].y << "): "
                 << calcularEcuacionRecta(coordenadas[i], coordenadas[j]) << endl;
        }
    }

    return 0;
}