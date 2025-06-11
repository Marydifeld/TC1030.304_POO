#include "Serie.h"

Serie::Serie() : Video() {}

Serie::Serie(int nuevo_id, string nuevo_nombre, double nueva_duracion, string nuevo_genero)
    : Video(nuevo_id, nuevo_nombre, nueva_duracion, nuevo_genero) {}

void Serie::agregarEpisodio(const Episodio &ep)
{
    episodios.push_back(ep);
}

int Serie::calculaEpisodios() const
{
    return episodios.size();
}

double Serie::calculaDuracion() const
{
    double total = 0.0;
    for (int i = 0; i < episodios.size(); i++)
    {
        total += episodios[i].getDuracion();
    }
    return total;
}

double Serie::calculaPromedio() const
{
    if (episodios.empty())
        return 0.0;
    double suma = 0.0;
    for (int i = 0; i < episodios.size(); i++)
    {
        suma += episodios[i].getCalificacion();
    }
    return suma / episodios.size();
}

void Serie::mostrarInfo() const
{
    cout << "Serie: " << nombre << " | Genero: " << genero
         << " | Calificacion promedio: " << calculaPromedio() << endl;
    for (int i = 0; i < episodios.size(); i++)
    {
        episodios[i].mostrar();
    }
}
