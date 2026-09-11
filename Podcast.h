#pragma once
#include <iostream>
#include <string>
#include "audio.h"

class Podcast : public Audio {
private:
    std::string tema;
public:
    Podcast(std::string t, std::string c, double d, double v, std::string tem) 
        : Audio(t, c, d, v), tema(tem) {}

    void mostrarDetalles() const override {
        std::cout << "[Podcast] " << titulo << " - " << creador 
             << " (" << duracion << "min) | Tema: " << tema << "\n";
    }
};