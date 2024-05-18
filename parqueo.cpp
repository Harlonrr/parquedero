#include <iostream>
using namespace std;

struct Nodo {
    string tipo;
    int value;
    Nodo* siguiente;
};

Nodo* top = nullptr;
int total_dinero_paqueo = 0;
int total_dinero_movimiento = 0;

void ingresarVehiculo() {
    Nodo* nuevoNodo = new Nodo();
    string tipo;
    cout << "Ingrese el tipo de vehiculo (auto/moto): ";
    cin >> tipo;
    nuevoNodo->tipo = tipo;
    if (tipo == "auto") {
        nuevoNodo->value = 6000;
    } else if (tipo == "moto") {
        nuevoNodo->value = 3000;
    }
    nuevoNodo->siguiente = top;
    top = nuevoNodo;
    total_dinero_paqueo += nuevoNodo->value - 1000;
    total_dinero_movimiento += 1000;
}

void sacarVehiculo() {
    if (top != nullptr) {
        Nodo* temp = top;
        top = top->siguiente;
        delete temp;
    } else {
        cout << "El parqueadero está vacío." << endl;
    }
}

void mostrarDinero() {
    cout << "Dinero por parqueo: " << total_dinero_paqueo << endl;
    cout << "Dinero por movimiento: " << total_dinero_movimiento << endl;
}

Nodo* obtenerTopAux() {
    return top;
}

int main() {
    int opcion;
    do {
        cout << "Menu:" << endl;
        cout << "1. Ingresar auto" << endl;
        cout << "2. Ingresar moto" << endl;
        cout << "3. Sacar vehiculo" << endl;
        cout << "4. Mostrar dinero manejado" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                ingresarVehiculo();
                break;
            case 2:
                ingresarVehiculo();
                break;
            case 3:
                sacarVehiculo();
                break;
            case 4:
                mostrarDinero();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor ingrese una opcion valida." << endl;
        }
    } while (opcion != 5);
    return 0;
}

