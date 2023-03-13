#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class StaticQueue {
private:
    int data[MAX_SIZE];
    int frontIndex, rearIndex;

public:
    StaticQueue() {
        frontIndex = rearIndex = -1;
    }

    bool isEmpty() {
        return frontIndex == -1;
    }

    bool isFull() {
        return (rearIndex + 1) % MAX_SIZE == frontIndex;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "La cola esta llena." << endl;
            return;
        }

        if (isEmpty()) {
            frontIndex = rearIndex = 0;
        }
        else {
            rearIndex = (rearIndex + 1) % MAX_SIZE;
        }

        data[rearIndex] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "La cola esta vacia." << endl;
            return;
        }

        if (frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;
        }
        else {
            frontIndex = (frontIndex + 1) % MAX_SIZE;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "La cola está vacia." << endl;
            return -1;
        }

        return data[frontIndex];
    }
};

int main() {
    StaticQueue myQueue;

    int choice;
    do {
        cout << endl;
        cout << "Menu de opciones:" << endl;
        cout << "1. Verificar si la cola esta vacia" << endl;
        cout << "2. Verificar si la cola esta llena" << endl;
        cout << "3. Ingresar un elemento a la cola" << endl;
        cout << "4. Eliminar un elemento de la cola" << endl;
        cout << "5. Obtener el primer elemento de la cola" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (myQueue.isEmpty()) {
                cout << "La cola esta vacia." << endl;
            }
            else {
                cout << "La cola no esta vacia." << endl;
            }
            break;
        case 2:
            if (myQueue.isFull()) {
                cout << "La cola esta llena." << endl;
            }
            else {
                cout << "La cola no esta llena." << endl;
            }
            break;
        case 3:
            int value;
            cout << "Ingrese el valor a añadir: ";
            cin >> value;
            myQueue.enqueue(value);
            break;
        case 4:
            myQueue.dequeue();
            break;
        case 5:
            cout << "El primer elemento de la cola es: " << myQueue.getFront() << endl;
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor intente de nuevo." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}