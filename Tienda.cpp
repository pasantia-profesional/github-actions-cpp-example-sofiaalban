#include "Tienda.h"
#include <iostream>

Tienda::Tienda() {}

Tienda::~Tienda() {
    for (auto& par : productos) {
        delete par.second;
    }
    productos.clear();
}

void Tienda::inicializarProductos() {
    crearProducto(1, "Laptop", 1200.50, 10);
    crearProducto(2, "Mouse", 25.99, 50);
    crearProducto(3, "Teclado", 75.00, 30);
    crearProducto(4, "Monitor", 350.75, 15);
    crearProducto(5, "Webcam", 89.99, 20);
        
    crearProducto(6, "Audífonos", 129.90, 40);
    crearProducto(7, "Memoria", 799.00, 5);
    crearProducto(8, "Disco Duro", 399.00, 12);

}

void Tienda::crearProducto(int id, const std::string& nombre, double precio, int cantidad) {
    if (productos.find(id) != productos.end()) {
        std::cout << "Error: Ya existe un producto con ID " << id << std::endl;
        return;
    }
    productos[id] = new Producto(id, nombre, precio, cantidad);
    std::cout << "Producto creado exitosamente." << std::endl;
}

Producto* Tienda::leerProducto(int id) {
    auto it = productos.find(id);
    if (it != productos.end()) {
        return it->second;
    }
    return nullptr;
}

void Tienda::actualizarProducto(int id, const std::string& nombre, double precio, int cantidad) {
    Producto* producto = leerProducto(id);
    if (producto == nullptr) {
        std::cout << "Error: Producto con ID " << id << " no encontrado." << std::endl;
        return;
    }
    producto->setNombre(nombre);
    producto->setPrecio(precio);
    producto->setCantidad(cantidad);
    std::cout << "Producto actualizado exitosamente." << std::endl;
}

void Tienda::eliminarProducto(int id) {
    auto it = productos.find(id);
    if (it == productos.end()) {
        std::cout << "Error: Producto con ID " << id << " no encontrado." << std::endl;
        return;
    }
    delete it->second;
    productos.erase(it);
    std::cout << "Producto eliminado exitosamente." << std::endl;
}

void Tienda::mostrarTodosProductos() const {
    if (productos.empty()) {
        std::cout << "No hay productos en la tienda." << std::endl;
        return;
    }
    std::cout << "\n=== Lista de Productos ===" << std::endl;
    for (const auto& par : productos) {
        par.second->mostrarInfo();
    }
    std::cout << "=========================\n" << std::endl;
}
