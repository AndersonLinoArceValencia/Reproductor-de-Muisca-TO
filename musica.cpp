#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Cancion {
    string titulo, artista, genero;
    double duracion, valoracion;
};

int main() {
    vector<Cancion> lista;
    int opcion;
    
    cout << "LISTA DE MUSICA \n";
    
    do {
        cout << "\n1. Agregar\n2. Listado\n3. Duracion total\n4. Promedio\n5. Genero\n6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        
        if (opcion == 1) {
            Cancion c;
            cin.ignore(); 
            cout << "Titulo: "; getline(cin, c.titulo);
            cout << "Artista: "; getline(cin, c.artista);
            cout << "Duracion (min): "; cin >> c.duracion;
            cout << "oracion (1-5): "; cin >> c.valoracion;
            cin.ignore(); 
            cout << "Genero: "; getline(cin, c.genero);
            lista.push_back(c);
            cout << "Agregada!\n";
        }
        else if (opcion == 2) {
            if (lista.empty()) { cout << "no hay canciones.\n"; continue; }
            cout << "\nlista de canciones:\n";
            for (int i = 0; i < lista.size(); i++) {
                cout << i+1 << ". " << lista[i].titulo << " - " << lista[i].artista
                     << " (" << lista[i].duracion << "min) | " << lista[i].genero << "\n";
            }
        }
        else if (opcion == 3) {
            if (lista.empty()) { cout << "no hay canciones.\n"; continue; }
            double total = 0;
            for (int i = 0; i < lista.size(); i++) total += lista[i].duracion;
            cout << "duracion: " << total << " min\n";
        }
        else if (opcion == 4) {
            if (lista.empty()) { cout << "no hay canciones.\n"; continue; }
            double total = 0;
            for (int i = 0; i < lista.size(); i++) total += lista[i].valoracion;
            cout << "promedio: " << total / lista.size() << " puntos\n";
        }
        else if (opcion == 5) {
            if (lista.empty()) { cout << "no hay canciones.\n"; continue; }
            string gen;
            cin.ignore();
            cout << "Genero: "; getline(cin, gen);
            cout << "\nCanciones de " << gen << ":\n";
            
            bool hay_canciones = false;
            for (int i = 0; i < lista.size(); i++) {
                if (lista[i].genero == gen) {
                    cout << "- " << lista[i].titulo << " - " << lista[i].artista << "\n";
                    hay_canciones = true;
                }
            }
            if (!hay_canciones) cout << "No se encontraron canciones de ese genero.\n";
        }
    } while (opcion != 6);
    
    cout << "adios\n";
    return 0;
}