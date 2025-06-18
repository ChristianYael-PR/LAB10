#include <iostream>
#include <vector>
#include <string>

struct Objeto {
    std::string nombre;
    int peso;
    int valor;
};

int main() {
    // 1) Definición de los objetos
    std::vector<Objeto> objetos = {
        {"Guitarra", 1, 1500},
        {"Laptop",   3, 2000},
        {"Estéreo",  4, 3000},
        {"iPhone",   1, 2000}
    };

    int n = objetos.size();
    int W = 4;  // capacidad máxima de la mochila

    // 2) Creamos la tabla dp[n+1][W+1], donde dp[i][w] = valor óptimo
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(W+1, 0));

    // 3) Llenado de la tabla
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Si no incluimos el objeto i-ésimo
            dp[i][w] = dp[i-1][w];
            // Si podemos incluirlo, vemos si mejora
            if (objetos[i-1].peso <= w) {
                dp[i][w] = std::max(
                    dp[i][w],
                    dp[i-1][w - objetos[i-1].peso] + objetos[i-1].valor
                );
            }
        }
    }

    // 4) Mostramos la tabla completa
    std::cout << "Tabla (filas: objetos, columnas: capacidad 0..4):\n";
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            std::cout << dp[i][w] << "\t";
        }
        std::cout << "\n";
    }

    // 5) Recuperación de la solución
    int res = dp[n][W];
    std::cout << "\nValor máximo: $" << res << "\n";
    std::cout << "Objetos seleccionados:\n";
    int w = W;
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i-1][w]) {
            // el objeto i-ésimo está en la solución
            std::cout << " - " << objetos[i-1].nombre
                      << " (peso " << objetos[i-1].peso
                      << ", valor $" << objetos[i-1].valor << ")\n";
            w -= objetos[i-1].peso;
        }
    }

    return 0;
}

