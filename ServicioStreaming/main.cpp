#include "Pelicula.h"
#include "Serie.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

int main()
{
    vector<Video *> videos;
    Serie *serieActual = nullptr;
    int idCounter = 1;

    int opcion;

    do
    {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Mostrar videos por calificación o género" << endl;
        cout << "3. Mostrar episodios de una serie por calificación" << endl;
        cout << "4. Mostrar películas por calificación (usa << operador)" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida.\n";
            continue;
        }

        if (opcion == 1)
        {
        
            for (auto v : videos)
                delete v;
            videos.clear();

            ifstream archivo("datos.txt");
            string linea;
            serieActual = nullptr;

            while (getline(archivo, linea))
            {
                if (linea.empty())
                    continue;

                string tipo;
                istringstream stream(linea);
                getline(stream, tipo, ',');

                if (tipo == "Pelicula")
                {
                    string nombre, genero;
                    double duracion, calificacion;

                    getline(stream, nombre, ',');
                    getline(stream, genero, ',');
                    stream >> duracion;
                    stream.ignore();
                    stream >> calificacion;

                    Pelicula *pelicula = new Pelicula(idCounter++, nombre, duracion, genero);
                    pelicula->agregarCalificacion(calificacion);
                    videos.push_back(pelicula);
                }
                else if (tipo == "Serie")
                {
                    string nombre, genero;
                    getline(stream, nombre, ',');
                    getline(stream, genero, ',');

                    serieActual = new Serie(idCounter++, nombre, 0.0, genero);
                    videos.push_back(serieActual);
                }
                else if (tipo == "Episodio" && serieActual != nullptr)
                {
                    string titulo;
                    int temporada;
                    double duracion, calificacion;

                    getline(stream, titulo, ',');
                    stream >> temporada;
                    stream.ignore();
                    stream >> duracion;
                    stream.ignore();
                    stream >> calificacion;

                    Episodio ep(temporada, titulo, duracion, temporada, calificacion);
                    serieActual->agregarEpisodio(ep);
                }
            }

            archivo.close();
            cout << "Datos cargados correctamente." << endl;
        }
        else if (opcion == 2)
        {
            string criterio;
            cout << "¿Filtrar por calificación o género? (c/g): ";
            cin >> criterio;

            if (criterio == "c")
            {
                double minCal;
                cout << "Calificación mínima: ";
                cin >> minCal;
                for (auto v : videos)
                {
                    if (v->obtenerPromedio() >= minCal)
                        v->mostrarInfo();
                }
            }
            else if (criterio == "g")
            {
                string gen;
                cout << "Género: ";
                cin >> gen;
                for (auto v : videos)
                {
                    if (v->getGenero() == gen)
                        v->mostrarInfo();
                }
            }
        }
        else if (opcion == 3)
        {
            string nombreSerie;
            double minCal;
            cout << "Nombre de la serie: ";
            cin.ignore();
            getline(cin, nombreSerie);
            cout << "Calificación mínima: ";
            cin >> minCal;

            for (auto v : videos)
            {
                Serie *s = dynamic_cast<Serie *>(v);
                if (s && s->getNombre() == nombreSerie)
                {
                    cout << "Episodios con calificación >= " << minCal << ":" << endl;
                    s->mostrarInfo();
                }
            }
        }
        else if (opcion == 4)
        {
            double minCal;
            cout << "Calificación mínima: ";
            cin >> minCal;

            for (auto v : videos)
            {
                Pelicula *p = dynamic_cast<Pelicula *>(v);
                if (p && p->obtenerPromedio() >= minCal)
                {
                    cout << *p << endl;
                }
            }
        }
        else if (opcion == 5)
        {
            string titulo;
            double cal;
            cout << "Título del video: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Calificación a agregar: ";
            cin >> cal;

            bool encontrado = false;
            for (auto v : videos)
            {
                if (v->getNombre() == titulo)
                {
                    v->agregarCalificacion(cal);
                    cout << "Calificación registrada." << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Video no encontrado." << endl;
        }
        else if (opcion != 0)
        {
            cout << "Opción inválida." << endl;
        }

    } while (opcion != 0);

    
    for (auto v : videos)
        delete v;

    return 0;
}

}
