#include "Pelicula.h"

Pelicula::Pelicula() : Video() {}

Pelicula::Pelicula(int id, string nombre, double duracion, string genero)
    : Video(id, nombre, duracion, genero) {}

void Pelicula::mostrarInfo() const {
    cout << "Pelicula: " << nombre << " | Genero: " << genero
         << " | Duracion: " << duracion << " min | Calificación Promedio: "
         << obtenerPromedio() << endl;
}
