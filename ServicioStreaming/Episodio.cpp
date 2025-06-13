#include "Episodio.h"

Episodio::Episodio() {
    titulo = "Sin titulo";
    duracion = 0;
    temporada = 0;
    calificacion = 0;
}

Episodio::Episodio(string t, double d, int temp, double c) {
    titulo = t;
    duracion = d;
    temporada = temp;
    calificacion = c;
}

void Episodio::mostrar() const {
    cout << "Episodio: " << titulo
         << " | Temporada: " << temporada
         << " | Duracion: " << duracion
         << " | Calificacion: " << calificacion << endl;
}

double Episodio::getDuracion() const {
    return duracion;
}

double Episodio::getCalificacion() const {
    return calificacion;
}
