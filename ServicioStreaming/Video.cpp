#include "Video.h"
#include <numeric>

Video::Video()
{
    id = 0;
    nombre = "Sin nombre";
    duracion = 0.0;
    genero = "Sin genero";
}

Video::Video(int nuevo_id, string nuevo_nombre, double nueva_duracion, string nuevo_genero)
{
    id = nuevo_id;
    nombre = nuevo_nombre;
    duracion = nueva_duracion;
    genero = nuevo_genero;
}

Video::~Video() {}

void Video::agregarCalificacion(double cal)
{
    calificaciones.push_back(cal);
}

double Video::obtenerPromedio() const
{
    if (calificaciones.empty())
        return 0.0;
    double suma = 0.0;
    for (int i = 0; i < calificaciones.size(); i++)
    {
        suma += calificaciones[i];
    }
    return suma / calificaciones.size();
}

string Video::getGenero() const
{
    return genero;
}

string Video::getNombre() const
{
    return nombre;
}
