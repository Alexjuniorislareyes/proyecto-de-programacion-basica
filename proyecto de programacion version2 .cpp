#include <iostream>
#include <string>

using namespace std;

struct Objeto {
    string nombre;
    int cantidad;
};

void mostrarInventario(const Objeto inventario[], int tam) {
    cout << "Inventario actual:" << endl;
    for (int i = 0; i < tam; ++i) {
        cout << "Nombre: " << inventario[i].nombre << ", Cantidad: " << inventario[i].cantidad << endl;
    }
    cout << "-----------------------------" << endl;
}

void agregarObjeto(Objeto inventario[], int &tam) {
    string nombre;
    int cantidad;
    
    cout << "Ingrese el nombre del objeto: ";
    cin >> nombre;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    inventario[tam].nombre = nombre;
    inventario[tam].cantidad = cantidad;
    ++tam;

    cout << "Objeto agregado al inventario." << endl;
}

void quitarObjeto(Objeto inventario[], int &tam) {
    string nombre;
    
    cout << "Ingrese el nombre del objeto que desea quitar: ";
    cin >> nombre;

    for (int i = 0; i < tam; ++i) {
        if (inventario[i].nombre == nombre) {
            
            int cantidadQuitada;
            cout << "Ingrese la cantidad que desea quitar: ";
            cin >> cantidadQuitada;

            
            if (cantidadQuitada <= inventario[i].cantidad) {
                inventario[i].cantidad -= cantidadQuitada;
                cout << "Objeto quitado del inventario." << endl;
                
            } else {
                cout << "No hay suficiente cantidad para quitar." << endl;
            }

            return; 
        }
    }

    cout << "El objeto no está en el inventario." << endl;
}


int main() {
    const int capacidadMaxima = 100;
    Objeto inventario[capacidadMaxima];
    int tam = 0;

    int opcion;
    do {
        
        cout << "1. Mostrar inventario" << endl;
        cout << "2. Agregar objeto" << endl;
        cout << "3. Quitar objeto" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarInventario(inventario, tam);
                break;
            case 2:
                agregarObjeto(inventario, tam);
                break;
            case 3:
                quitarObjeto(inventario, tam);
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}
