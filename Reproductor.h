#pragma once
#include <iostream>
#include <vector>
#include "audio.h"
#include "cancion.h"
#include "Podcast.h"

class Reproductor {
private:
    vector<Audio*> lista; 

public:
    ~Reproductor() {
        for (Audio* a : lista) delete a; 
    }

    void agregar(Audio* a) {
        lista.push_back(a);
        cout << "Agregado correctamente!\n";
    }

    void listar() const {
        if (lista.empty()) { cout << "La lista esta vacia.\n"; return; }
        cout << "\n--- LISTA DE REPRODUCCION ---\n";
        for (size_t i = 0; i < lista.size(); i++) {
            cout << i + 1 << ". ";
            lista[i]->mostrarDetalles();
        }
    }

    void mostrarDuracion() const {
        if (lista.empty()) { cout << "La lista esta vacia.\n"; return; }
        double total = 0;
        for (Audio* a : lista) total += a->getDuracion();
        cout << "Duracion total: " << total << " min\n";
    }

    void mostrarPromedio() const {
        if (lista.empty()) { cout << "La lista esta vacia.\n"; return; }
        double total = 0;
        for (Audio* a : lista) total += a->getValoracion();
        cout << "Promedio general: " << total / lista.size() << " puntos\n";
    }

    void buscarPorCreador(string creadorBuscado) const {
        if (lista.empty()) { cout << "La lista esta vacia.\n"; return; }
        bool encontrado = false;
        cout << "\nResultados para '" << creadorBuscado << "':\n";
        for (Audio* a : lista) {
            if (a->getCreador() == creadorBuscado) {
                cout << "- ";
                a->mostrarDetalles();
                encontrado = true;
            }
        }
        if (!encontrado) cout << "No se encontraron resultados.\n";
    }
};