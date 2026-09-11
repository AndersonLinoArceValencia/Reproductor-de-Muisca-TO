#include <iostream>
#include <string>
#include "Reproductor.h" 
using namespace std;

int main() {
    Reproductor miReproductor;
    int opcion;
    
    cout << "REPRODUCTOR GATO\n";
    
    do {
        cout << "\n1. Agregar Cancion\n2. Agregar Podcast\n3. Listado\n4. Duracion total\n5. Promedio\n6. Buscar por Creador\n7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        
        if (opcion == 1 || opcion == 2) {
            string tit, crea, extra;
            double dur, val;
            
            cin.ignore(); 
            cout << "Titulo: "; getline(cin, tit);
            cout << (opcion == 1 ? "Artista: " : "Host/Creador: "); getline(cin, crea);
            cout << "Duracion (min): "; cin >> dur;
            cout << "Valoracion (1-5): "; cin >> val;
            cin.ignore(); 
            
            if (opcion == 1) {
                cout << "Genero: "; getline(cin, extra);
                miReproductor.agregar(new Cancion(tit, crea, dur, val, extra));
            } else {
                cout << "Tema principal: "; getline(cin, extra);
                miReproductor.agregar(new Podcast(tit, crea, dur, val, extra));
            }
        }
        else if (opcion == 3) miReproductor.listar();
        else if (opcion == 4) miReproductor.mostrarDuracion();
        else if (opcion == 5) miReproductor.mostrarPromedio();
        else if (opcion == 6) {
            string creador;
            cin.ignore();
            cout << "Nombre del Artista o Host a buscar: "; getline(cin, creador);
            miReproductor.buscarPorCreador(creador);
        }
    } while (opcion != 7);
    
    cout << "Adios!\n";
    return 0;
}