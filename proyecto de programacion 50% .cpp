#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

// Función para limpiar el búfer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Estructuras
struct Objeto {
    string nombre;
    int cantidad;
};

struct Animal {
    string nombre;
    int cantidad;
};

// Funciones 
void mostrarInventario(const Objeto inventario[], int tam) {
    cout << "Inventario actual de objetos:" << endl;
    for (int i = 0; i < tam; ++i) {
        cout << "Nombre: " << inventario[i].nombre << ", Cantidad: " << inventario[i].cantidad << endl;
    }
    cout << "-----------------------------" << endl;
      // Agregar una pausa
    cout << "Presione Enter para continuar...";
    limpiarBuffer();  // Limpiar el buffer antes de pausar
    cin.ignore();     // Esperar a que el usuario presione Enter
}

void agregarObjeto(Objeto inventario[], int &tam) {
    string nombre;
    int cantidad;

    cout << "Ingrese el nombre del objeto: ";
    limpiarBuffer();
    getline(cin, nombre);

    cout << "Ingrese la cantidad: ";
    while (!(cin >> cantidad)) {
        cout << "Por favor, ingrese un valor valido para la cantidad." << endl;
        limpiarBuffer();
    }

    inventario[tam].nombre = nombre;
    inventario[tam].cantidad = cantidad;
    ++tam;

    cout << "Objeto agregado al inventario." << endl;
}

void quitarObjeto(Objeto inventario[], int &tam) {
    string nombre;

    cout << "Ingrese el nombre del objeto que desea quitar: ";
    limpiarBuffer();
    getline(cin, nombre);

    int indice = -1;  // Variable para almacenar el índice del objeto a quitar

    for (int i = 0; i < tam; ++i) {
        if (inventario[i].nombre == nombre) {
            indice = i;
            break;  // Salir del bucle una vez que se encuentra el objeto
        }
    }

    if (indice != -1) {
        int cantidadQuitada;
        cout << "Ingrese la cantidad que desea quitar: ";
        while (!(cin >> cantidadQuitada)) {
            cout << "Por favor, ingrese un valor válido para la cantidad." << endl;
            limpiarBuffer();
        }

        if (cantidadQuitada <= inventario[indice].cantidad) {
            inventario[indice].cantidad -= cantidadQuitada;

            // Si la cantidad llega a cero, eliminar el objeto del inventario
            if (inventario[indice].cantidad == 0) {
                for (int j = indice; j < tam - 1; ++j) {
                    inventario[j] = inventario[j + 1];
                }
                --tam;
            }

            cout << "Objeto quitado del inventario." << endl;
        } else {
            cout << "No hay suficiente cantidad para quitar." << endl;
        }
    } else {
        cout << "El objeto no está en el inventario." << endl;
    }

    limpiarBuffer();
}

void obtenerPreferencias(vector<string>& preferencias) {
    cout << "Por favor, ingrese la información del animal:" << endl;

    cout << "1. Tipo de alimentacion (vegetariano, carnivoro, omnivoro, etc.): ";
    limpiarBuffer();
    getline(cin, preferencias[0]);

    cout << "2. Edad del animal: ";
    while (!(cin >> preferencias[1])) {
        cout << "Por favor, ingrese un valor valido para la edad." << endl;
        limpiarBuffer();
    }

    cout << "3. Estado del animal (saludable, enfermo, anciano, etc.): ";
    limpiarBuffer();
    getline(cin, preferencias[2]);

    limpiarBuffer();
   

}

void recomendarAlimentos(const string& tipoAnimal, const vector<string>& preferencias) {
    unordered_map<string, int> alimentosNecesarios;

    for (const string& preferencia : preferencias) {
        if (preferencia == "vegetariano") {
            alimentosNecesarios["Frutas"] += 3;
            alimentosNecesarios["Verduras"] += 4;
            alimentosNecesarios["Legumbres"] += 2;
        }

        if (preferencia == "carnivoro") {
            alimentosNecesarios["Carne"] += 5;
            alimentosNecesarios["Pescado"] += 3;
        }

        if (preferencia == "omnivoro") {
            alimentosNecesarios["Frutas"] += 2;
            alimentosNecesarios["Verduras"] += 3;
            alimentosNecesarios["Carne"] += 4;
        }
    }

    cout << "Cantidad de alimentos recomendados para " << tipoAnimal << " (" << preferencias[2] << "):" << endl;

    if (preferencias[2] == "saludable") {
        cout << "- Ofrecer agua fresca diariamente." << endl;
        cout << "- Proporcionar una dieta balanceada según las preferencias alimentarias." << endl;
    } else if (preferencias[2] == "enfermo") {
        cout << "- Consultar con el veterinario para una dieta especifica según la enfermedad." << endl;
        cout << "- Mantener la hidratacion con agua fresca y limpia." << endl;
    } else if (preferencias[2] == "anciano") {
        cout << "- Considerar una dieta baja en grasas para animales ancianos." << endl;
        cout << "- Ofrecer alimentos que promuevan la salud articular." << endl;
    } else {
        cout << "- Recomendaciones generales para el estado del animal." << endl;
    }

    cout << "Cantidad de alimentos recomendados:" << endl;
    for (const auto& par : alimentosNecesarios) {
        cout << "- " << par.first << ": " << par.second << " unidades diarias" << endl;
    }
       // Agregar una pausa
    cout << "Presione Enter para continuar...";
    limpiarBuffer();  // Limpiar el buffer antes de pausar
    cin.ignore();     // Esperar a que el usuario presione Enter
   
}

void mostrarInventarioAnimales(const Animal inventario[], int tam) {
    cout << "Inventario actual de animales:" << endl;
    for (int i = 0; i < tam; ++i) {
        cout << "Nombre: " << inventario[i].nombre << ", Cantidad: " << inventario[i].cantidad << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "Presione Enter para continuar...";
    limpiarBuffer();  // Limpiar el buffer antes de pausar
    cin.ignore();     // Esperar a que el usuario presione Enter
}

void agregarAnimal(Animal inventario[], int &tam) {
    string nombre;
    int cantidad;

    cout << "Ingrese el nombre del animal: ";
    limpiarBuffer();
    getline(cin, nombre);

    cout << "Ingrese la cantidad: ";
    while (!(cin >> cantidad)) {
        cout << "Por favor, ingrese un valor válido para la cantidad." << endl;
        limpiarBuffer();
    }

    inventario[tam].nombre = nombre;
    inventario[tam].cantidad = cantidad;
    ++tam;

    cout << "Animal agregado al inventario." << endl;
}

void quitarAnimal(Animal inventario[], int &tam) {
    string nombre;

    cout << "Ingrese el nombre del animal que desea quitar: ";
    limpiarBuffer();
    getline(cin, nombre);

    int indice = -1;  // Variable para almacenar el índice del animal a quitar

    for (int i = 0; i < tam; ++i) {
        if (inventario[i].nombre == nombre) {
            indice = i;
            break;  // Salir del bucle una vez que se encuentra el animal
        }
    }

    if (indice != -1) {
        int cantidadQuitada;
        cout << "Ingrese la cantidad que desea quitar: ";
        while (!(cin >> cantidadQuitada) || cantidadQuitada <= 0) {
            cout << "Por favor, ingrese una cantidad valida mayor que cero." << endl;
            limpiarBuffer();
        }

        if (cantidadQuitada <= inventario[indice].cantidad) {
            inventario[indice].cantidad -= cantidadQuitada;

            // Si la cantidad llega a cero, eliminar el animal del inventario
            if (inventario[indice].cantidad == 0) {
                for (int j = indice; j < tam - 1; ++j) {
                    inventario[j] = inventario[j + 1];
                }
                --tam;
            }

            cout << "Animal quitado del inventario." << endl;
        } else {
            cout << "No hay suficiente cantidad para quitar." << endl;
        }
    } else {
        cout << "El animal no esta en el inventario." << endl;
    }

    limpiarBuffer();
}


// Función principal
int main() {
    const int capacidadMaximaObjetos = 100;
    Objeto inventarioObjetos[capacidadMaximaObjetos];
    int tamObjetos = 0;

    const int capacidadMaximaAnimales = 100;
    Animal inventarioAnimales[capacidadMaximaAnimales];
    int tamAnimales = 0;

    int opcion;

    do {
        // Limpiar la pantalla
        system("cls");

        cout << "1. Mostrar inventario de objetos" << endl;
        cout << "2. Agregar objeto" << endl;
        cout << "3. Quitar objeto" << endl;
        cout << "4. Mostrar inventario de animales" << endl;
        cout << "5. Agregar animal" << endl;
        cout << "6. Quitar animal" << endl;
        cout << "7. Obtener preferencias y recomendar alimentos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Por favor, ingrese un valor valido para la opción." << endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1:
                mostrarInventario(inventarioObjetos, tamObjetos);
                break;
            case 2:
                agregarObjeto(inventarioObjetos, tamObjetos);
                break;
            case 3:
                quitarObjeto(inventarioObjetos, tamObjetos);
                break;
            case 4:
                mostrarInventarioAnimales(inventarioAnimales, tamAnimales);
                break;
            case 5:
                agregarAnimal(inventarioAnimales, tamAnimales);
                break;
            case 6:
                quitarAnimal(inventarioAnimales, tamAnimales);
                break;
            case 7:
            {
                vector<string> preferencias(3, "");
                string tipoAnimal;

                cout << "Ingrese el tipo de animal (por ejemplo, perro, gato, etc.): ";
                limpiarBuffer();
                getline(cin, tipoAnimal);

                obtenerPreferencias(preferencias);
                recomendarAlimentos(tipoAnimal, preferencias);
            }
            break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no valida. Intentelo de nuevo." << endl;
                limpiarBuffer();
        }
    } while (opcion != 0);

    return 0;
}
