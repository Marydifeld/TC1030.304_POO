#include "Serie.h"

Serie::Serie() : Video() {}

Serie::Serie(int id, string nombre, double duracion, string genero)
    : Video(id, nombre, duracion, genero) {}

void Serie::agregarEpisodio(Episodio e) {
    episodios.push_back(e);
}

void Serie::mostrarInfo() const {
    cout << "Serie: " << nombre << " | Genero: " << genero
         << " | Calificacion promedio: ";
    double suma = 0;
    for (int i = 0; i < episodios.size(); i++) {
        suma += episodios[i].getCalificacion();
    }
    cout << (episodios.empty() ? 0 : suma / episodios.size()) << endl;

    for (int i = 0; i < episodios.size(); i++) {
        episodios[i].mostrar();
    }
}
