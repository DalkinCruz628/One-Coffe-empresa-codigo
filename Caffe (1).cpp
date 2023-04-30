#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // Definir el catálogo de productos
    string productos[] = {"Expreso", "Capuchino", "Con leche", "Americano", "Moca", "Vino tinto", "Sangría", "Carlos Rossi"};
    double precios[] = {50.00, 45.00, 50.00, 65.00, 60.00, 70.00, 219.00, 410.00};
    
    // Mostrar el catálogo de productos
    cout << "Catálogo de productos" << endl;
    cout << "---------------------" << endl;
    cout << "Bebidas sin Alcohol" << endl;
    for (int i = 0; i < 5; i++) {
        cout << productos[i] << ": " << setw(30 - productos[i].length()) << fixed << setprecision(2) << "$ " << precios[i] << endl;
    }
    cout << "Bebidas con Alcohol" << endl;
    for (int i = 5; i < 8; i++) {
        cout << productos[i] << ": " << setw(30 - productos[i].length()) << fixed << setprecision(2) << "$ " << precios[i] << endl;
    }
    
    // Pedir al usuario que seleccione los productos
    string seleccion;
    double total = 0.0;
    do {
        cout << "Ingrese el producto que desea (o 'salir' para terminar): ";
        getline(cin, seleccion);
        
        // Buscar el producto seleccionado en el catálogo
        int indice = -1;
        for (int i = 0; i < 8; i++) {
            if (seleccion == productos[i]) {
                indice = i;
                break;
            }
        }
        
        // Si el producto existe, agregar su precio al total
        if (indice >= 0) {
            total += precios[indice];
            cout << "Producto agregado al carrito." << endl;
        } else if (seleccion != "salir") {
            cout << "Producto no encontrado. Por favor ingrese un producto válido." << endl;
        }
    } while (seleccion != "salir");
    
    // Mostrar la factura con el total
    cout << "Total a pagar: $" << fixed << setprecision(2) << total << endl;
    
    return 0;
}
