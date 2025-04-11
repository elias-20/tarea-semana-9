#include <iostream>  // Incluye la librería estándar para entrada y salida (cout, endl, etc.)
using namespace std; // Permite usar directamente objetos del espacio de nombres std (como cout sin std::)

struct Nodo {         // Se define una estructura Nodo, que representa cada elemento de la pila
	int dato;         // El valor que almacenará el nodo
	Nodo* siguiente;  // Puntero al siguiente nodo en la pila (hacia abajo)
};

class pilaDinamica {  // Se declara una clase para manejar una pila de forma dinámica
private:
	Nodo* cima;       // Puntero al nodo en la cima de la pila (el último en entrar, primero en salir)

public:
	pilaDinamica() : cima(nullptr) {}  // Constructor: inicializa la pila como vacía (cima apunta a null)

	~pilaDinamica() {                  // Destructor: se encarga de liberar la memoria usada por los nodos
		while (cima != nullptr) {     // Mientras haya nodos en la pila
			pop();                    // Llama a pop() para eliminar cada nodo
		}
	}

	void push(int valor) {           // Función para insertar un elemento en la pila
		Nodo* nuevo = new Nodo;      // Se crea dinámicamente un nuevo nodo
		nuevo->dato = valor;         // Se asigna el valor recibido al nuevo nodo
		nuevo->siguiente = cima;     // El nuevo nodo apunta al nodo que estaba en la cima
		cima = nuevo;                // La cima de la pila ahora es el nuevo nodo
	}

	int pop() {                      // Función para eliminar y devolver el valor de la cima
		if (cima == nullptr) {      // Verifica si la pila está vacía
			cout << "pila vacia (underflow)." << endl;
			return -1;              // Devuelve un valor de error
		}
		Nodo* temp = cima;          // Guarda el nodo actual de la cima
		int valor = temp->dato;     // Guarda el valor del nodo para retornarlo
		cima = cima->siguiente;     // La nueva cima es el siguiente nodo en la pila
		delete temp;                // Libera la memoria del nodo que fue eliminado
		return valor;               // Retorna el valor eliminado
	}

	int peek() const {              // Función para ver el valor de la cima sin eliminarlo
		if (cima == nullptr) {     // Verifica si la pila está vacía
			cout << "pila vacia." << endl;
			return -1;             // Devuelve un valor de error
		}
		return cima->dato;         // Retorna el valor de la cima
	}
};

int main() {                         // Función principal: punto de entrada del programa
	pilaDinamica pila;              // Se crea un objeto de la clase pilaDinamica

	pila.push(100);                 // Inserta 100 en la pila
	pila.push(200);                 // Inserta 200 en la pila
	pila.push(300);                 // Inserta 300 en la pila

	cout << "Elimina en la cima : " << pila.peek() << endl; // Muestra el valor en la cima (debería ser 300)

	cout << "Elemento eliminado: " << pila.pop() << endl;   // Elimina y muestra el valor 300
	cout << "Elemento eliminado: " << pila.pop() << endl;   // Elimina y muestra el valor 200

	return 0;                       // Fin del programa
}
