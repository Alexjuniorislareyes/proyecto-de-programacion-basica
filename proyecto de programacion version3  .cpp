#include <iostream>
#include <string>

using namespace std;

struct Animal {
    string nombre;
    int cantidad;
};

void mostrarInventarioAnimales(const Animal inventario[], int tam) {
    cout << "Inventario actual de animales:" << endl;
    for (int i = 0; i < tam; ++i) {
        cout << "Nombre: " << inventario[i].nombre << ", Cantidad: " << inventario[i].cantidad << endl;
    }
    cout << "-----------------------------" << endl;
}

void agregarAnimal(Animal inventario[], int &tam) {
    string nombre;
    int cantidad;

    cout << "Ingrese el nombre del animal: ";
    cin >> nombre;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    inventario[tam].nombre = nombre;
    inventario[tam].cantidad = cantidad;
    ++tam;

    cout << "Animal agregado al inventario." << endl;
}

int main() {
    const int capacidadMaximaAnimales = 100;
    Animal inventarioAnimales[capacidadMaximaAnimales];
    int tamAnimales = 0;

    int opcion;
    do {
        cout << "1. Mostrar inventario de animales" << endl;
        cout << "2. Agregar animal" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarInventarioAnimales(inventarioAnimales, tamAnimales);
                break;
            case 2:
                agregarAnimal(inventarioAnimales, tamAnimales);
                break;
            case 0:
                cout << "Saliendo del menú de animales." << endl;
                break;
            default:
                cout << "Opción no valida. Intentelo de nuevo." << endl;
        }
    } while (opcion != 0);


    return 0;
}
