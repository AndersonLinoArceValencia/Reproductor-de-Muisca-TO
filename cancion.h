#pragma once
#include <iostream>
#include "audio.h"

class Cancion : public Audio {
private:
    string genero;
public:
    Cancion(string t, string c, double d, double v, string g) 
        : Audio(t, c, d, v), genero(g) {}

    void mostrarDetalles() const override {
        cout << "[Cancion] " << titulo << " - " << creador 
             << " (" << duracion << "min) | Genero: " << genero << "\n";
    }
};