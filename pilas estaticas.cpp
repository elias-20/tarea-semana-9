#include <iostream> //incluye la biblioteca estandar de salida y entrada de datos
using namespace std; // Para evitar escribir std::cout y std::cin

class pilaEstatica { //Definicion de una clase llamda pilaEstatica (una pila con tamano fijo)
private: //seccion privada de la clase: solo puede ser accedido dentro de la misma clase.
	static const int MAX = 10; // Tamano fijo de la pila //Define el tamano de la fila como constante 
	int arr[MAX]; //arreglo que almacenara los elemento de la pila
	int top; // Indice del ultimo elemento insertado //Indice del ultimo elemento insertado (cima de la pila)

public: //seccion publica de la clase: puede ser accedido desde fuera de la clase.
	pilaEstatica () : top(-1) {} //Constructor: inicializa top en -1, indicando que la pila esta vacia
	bool push(int valor) { //Metodo para insertar un valor en la pila
		if (top >= MAX - 1) { //si el top alcanza el limite, la pila esta llena 
			cout << "Pila esta llena (over flow)." << endl; //muestra mensaje 
			return false; //Retorna falso porque no se pudo insertar 
		}
		arr[++top] = valor; //incrementa top e inserta el valor al arreglo
		return true; // Insercion exitosa
	}

	int pop() { //Metodo para eliminar (y retornar) el elemento de la coma de la pila
		if (top < 0) { //Si top es menor que 0, la pila esta vacia 
			cout << "pila esta vacia (under flow)." << endl; //muestra mensaje
			return -1; //Retorna -1 como valor de error 
		}
		return arr[top--]; //devuelve el elemento actual y luego decrementa top
	}

	int peek() const { //Metodo para ver elmento en la cima de la pila sin eliminarlo 
		if (top < 0) { //verifica si la pila esta vacia 
			cout << "pila vacia." << endl;
			return -1; //Retorna -1 como valor de error 
		}
		return arr[top]; //devuelve el valor en la cima cin modficar la pila
	}
};

int main() { //Funcion principal del progrma 
	pilaEstatica pila; //Crea una instancia de la pila 
	pila.push(10); //Inser el valor de 10 en la pila 
	pila.push(20); //Inserta el valor de 20 en la pila
	pila.push(30); //Inserta el valor de 30 en la pila
	cout << "Elemento en la cima: " << pila.peek() << endl; //Deberia mostrar el valor e la cima (30)
	cout << "Elemento eliminado: " << pila.pop() << endl; // Elimina y muestra el elemento en la cima (30
	cout << "Elemento eliminado: " << pila.pop() << endl; // Elimina y muestra el siguiente elemento (20)
	return 0; //fin del progrma 
}