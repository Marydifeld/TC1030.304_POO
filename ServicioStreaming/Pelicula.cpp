#include "Pelicula.h"

Pelicula::Pelicula() : Video() {}

Pelicula::Pelicula(int nuevo_id, string nuevo_nombre, double nueva_duracion, string nuevo_genero)
    : Video(nuevo_id, nuevo_nombre, nueva_duracion, nuevo_genero) {}

void Pelicula::mostrarInfo() const
{
    cout << "Pelicula: " << nombre << " | Genero: " << genero
         << " | Duracion: " << duracion << " min"
         << " | Calificacion promedio: " << obtenerPromedio() << endl;
}

ostream &operator<<(ostream &out, const Pelicula &p)
{
    out << "Pelicula: " << p.nombre
        << " | Genero: " << p.genero
        << " | Duracion: " << p.duracion << " min"
        << " | Calificacion promedio: " << p.obtenerPromedio();
    return out;
}

