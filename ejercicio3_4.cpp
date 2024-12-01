#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Estructura para representar una coordenada
struct Coordenada {
    double x;
    double y;
};

// Función para calcular la distancia entre dos puntos
double calcularDistancia(const Coordenada &p1, const Coordenada &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Función para verificar si un punto está dentro de los límites del cuadrante
bool estaEnCuadrante(const Coordenada &p, double xMin, double xMax, double yMin, double yMax) {
    return (p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax);
}

int main() {
    vector<Coordenada> puntos;
    double xMin, xMax, yMin, yMax;
    int n;

    // Ingresar los límites del cuadrante
    cout << "Ingrese los limites del cuadrante (xMin xMax yMin yMax): ";
    cin >> xMin >> xMax >> yMin >> yMax;

    // Ingresar el número de puntos
    cout << "Ingrese el numero de puntos: ";
    cin >> n;

    // Leer los puntos
    for (int i = 0; i < n; i++) {
        Coordenada punto;
        cout << "Ingrese el punto " << i + 1 << " (x y): ";
        cin >> punto.x >> punto.y;
        puntos.push_back(punto);
    }

    // Calcular la distancia máxima entre puntos dentro del cuadrante
    double distanciaMaxima = 0.0;
    Coordenada punto1Max, punto2Max;

    for (size_t i = 0; i < puntos.size(); i++) {
        for (size_t j = i + 1; j < puntos.size(); j++) {
            if (estaEnCuadrante(puntos[i], xMin, xMax, yMin, yMax) &&
                estaEnCuadrante(puntos[j], xMin, xMax, yMin, yMax)) {
                double distancia = calcularDistancia(puntos[i], puntos[j]);
                if (distancia > distanciaMaxima) {
                    distanciaMaxima = distancia;
                    punto1Max = puntos[i];
                    punto2Max = puntos[j];
                }
            }
        }
    }

    cout << "\nDistancia maxima entre puntos dentro del cuadrante: " << distanciaMaxima << endl;
    cout << "Entre los puntos (" << punto1Max.x << ", " << punto1Max.y << ") y (" << punto2Max.x << ", " << punto2Max.y << ")\n";

    // Calcular las distancias desde un punto específico a los demás dentro del cuadrante
    int indice;
    cout << "\nSeleccione el indice de un punto (1 a " << n << ") para calcular las distancias: ";
    cin >> indice;

    if (indice < 1 || indice > n) {
        cout << "Indice invalido." << endl;
        return 1;
    }

    Coordenada puntoSeleccionado = puntos[indice - 1];

    cout << "\nDistancias desde el punto (" << puntoSeleccionado.x << ", " << puntoSeleccionado.y << ") a los demas puntos dentro del cuadrante:\n";
    for (size_t i = 0; i < puntos.size(); i++) {
        if (i != static_cast<size_t>(indice - 1) && estaEnCuadrante(puntos[i], xMin, xMax, yMin, yMax)) {
            double distancia = calcularDistancia(puntoSeleccionado, puntos[i]);
            cout << "A (" << puntos[i].x << ", " << puntos[i].y << "): " << distancia << endl;
        }
    }

    return 0;
}