#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>  

using namespace std;

void obtenerPreferencias(vector<string>& preferencias) {
    cout << "Por favor, ingrese la información del animal:" << endl;

    cout << "1. Tipo de alimentación (vegetariano, carnivoro, omnivoro, etc.): ";
    string tipoAlimentacion;
    cin >> tipoAlimentacion;
    preferencias.push_back(tipoAlimentacion);

    cout << "2. Edad del animal: ";
    int edad;
    cin >> edad;
    preferencias.push_back(to_string(edad));

    cout << "3. Estado del animal (saludable, enfermo, anciano, etc.): ";
    string estado;
    cin >> estado;
    preferencias.push_back(estado);

    // Limpiar el búfer de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    cout << "Cantidad de alimentos recomendados para " << tipoAnimal << " (" << preferencias.back() << "):" << endl;

    if (preferencias.back() == "saludable") {
        cout << "- Ofrecer agua fresca diariamente." << endl;
        cout << "- Proporcionar una dieta balanceada segun las preferencias alimentarias." << endl;
    } else if (preferencias.back() == "enfermo") {
        cout << "- Consultar con el veterinario para una dieta especifica según la enfermedad." << endl;
        cout << "- Mantener la hidratación con agua fresca y limpia." << endl;
    } else if (preferencias.back() == "anciano") {
        cout << "- Considerar una dieta baja en grasas para animales ancianos." << endl;
        cout << "- Ofrecer alimentos que promuevan la salud articular." << endl;
    } else {
        cout << "- Recomendaciones generales para el estado del animal." << endl;
    }

    cout << "Cantidad de alimentos recomendados:" << endl;
    for (const auto& par : alimentosNecesarios) {
        cout << "- " << par.first << ": " << par.second << " unidades diarias" << endl;
    }
}

int main() {
    char opcion;

    do {
        vector<string> preferencias;
        string tipoAnimal;

        cout << "Ingrese el tipo de animal (por ejemplo, perro, gato, etc.): ";
        cin >> tipoAnimal;

        obtenerPreferencias(preferencias);
        recomendarAlimentos(tipoAnimal, preferencias);

        cout << "¿Desea ingresar otro animal? (S/N): ";
        cin >> opcion;

        
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (opcion == 'S' || opcion == 's');

    return 0;
}
