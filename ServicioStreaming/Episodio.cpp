#include "Episodio.h"

Episodio::Episodio()
{
    numEpisodio = 0;
    tituloEpisodio = "Sin titulo";
    duracion = 0.0;
    temporada = 0;
    calificacion = 0.0;
}

Episodio::Episodio(int numero, string titulo, double dur, int temp, double calif)
{
    numEpisodio = numero;
    tituloEpisodio = titulo;
    duracion = dur;
    temporada = temp;
    calificacion = calif;
}

double Episodio::getDuracion() const
{
    return duracion;
}

double Episodio::getCalificacion() const
{
    return calificacion;
}

void Episodio::mostrar() const
{
    cout << "  Episodio " << numEpisodio << ": " << tituloEpisodio
         << " | Temporada: " << temporada
         << " | Duracion: " << duracion
         << " | Calificacion: " << calificacion << endl;
}
