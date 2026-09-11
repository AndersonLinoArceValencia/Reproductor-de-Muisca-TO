#pragma once
#include <string>
using namespace std;

class Audio {
protected:
    string titulo, creador;
    double duracion, valoracion;

public:
    Audio(string t, string c, double d, double v) {
        titulo = t;
        creador = c;
        duracion= d;
        valoracion = v;
    }
    
    virtual ~Audio() {}
    virtual void mostrarDetalles() const = 0; 

    double getDuracion() const { return duracion; }
    double getValoracion() const { return valoracion; }
    string getCreador() const { return creador; }
};