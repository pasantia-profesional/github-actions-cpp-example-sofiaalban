#include "Tienda.h"
#include <iostream>
#include <limits>

void mostrarMenu() {
    std::cout << "\n=== Menu Principal ===" << std::endl;
    std::cout << "1. Mostrar todos los productos" << std::endl;
    std::cout << "2. Buscar producto por ID" << std::endl;
    std::cout << "3. Crear nuevo producto" << std::endl;
    std::cout << "4. Actualizar producto" << std::endl;
    std::cout << "5. Eliminar producto" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Tienda tienda;
    tienda.inicializarProductos();

    std::cout << "Bienvenido al Sistema de Gestion de Tienda" << std::endl;

    int opcion;
    bool salir = false;

    while (!salir) {
        mostrarMenu();
        std::cin >> opcion;  // leer una sola vez

        if (std::cin.fail()) {
            limpiarBuffer();
            std::cout << "Opcion invalida. Por favor ingrese un numero." << std::endl;
        } else {
            limpiarBuffer();

            switch (opcion) {
                case 1: {
                    tienda.mostrarTodosProductos();
                    break;
                }
                case 2: {
                    int id;
                    std::cout << "Ingrese el ID del producto: ";
                    std::cin >> id;
                    limpiarBuffer();

                    Producto* producto = tienda.leerProducto(id);
                    if (producto != nullptr) {
                        std::cout << "\nProducto encontrado:" << std::endl;
                        producto->mostrarInfo();
                    } else {
                        std::cout << "Producto no encontrado." << std::endl;
                    }
                    break;
                }
                case 3: {
                    int id, cantidad;
                    std::string nombre;
                    double precio;

                    std::cout << "Ingrese el ID del producto: ";
                    std::cin >> id;
                    limpiarBuffer();

                    std::cout << "Ingrese el nombre del producto: ";
                    std::getline(std::cin, nombre);

                    std::cout << "Ingrese el precio del producto: ";
                    std::cin >> precio;
                    limpiarBuffer();

                    std::cout << "Ingrese la cantidad del producto: ";
                    std::cin >> cantidad;
                    limpiarBuffer();

                    tienda.crearProducto(id, nombre, precio, cantidad);
                    break;
                }
                case 4: {
                    int id, cantidad;
                    std::string nombre;
                    double precio;

                    std::cout << "Ingrese el ID del producto a actualizar: ";
                    std::cin >> id;
                    limpiarBuffer();

                    std::cout << "Ingrese el nuevo nombre del producto: ";
                    std::getline(std::cin, nombre);

                    std::cout << "Ingrese el nuevo precio del producto: ";
                    std::cin >> precio;
                    limpiarBuffer();

                    std::cout << "Ingrese la nueva cantidad del producto: ";
                    std::cin >> cantidad;
                    limpiarBuffer();

                    tienda.actualizarProducto(id, nombre, precio, cantidad);
                    break;
                }
                case 5: {
                    int id;
                    std::cout << "Ingrese el ID del producto a eliminar: ";
                    std::cin >> id;
                    limpiarBuffer();

                    tienda.eliminarProducto(id);
                    break;
                }
                case 6: {
                    std::cout << "Gracias por usar el sistema. Adios!" << std::endl;
                    salir = true;
                    break;
                }
                default: {
                    std::cout << "Opcion invalida. Por favor seleccione una opcion del 1 al 6." << std::endl;
                    break;
                }
            } // switch
        }     // if/else
    }         // while

    return 0;
}
