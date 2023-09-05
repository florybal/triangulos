#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>

class triangle
{
    
    public:
        triangle();
        ~triangle();

        void run();
    private:
        void desenha();
        void processEvent();

        void mediatriz();
        void ponto_med();
        bool verificaTriangulo();
        void Mediana();
        void baricentro();
        void distance();
        void equacoes();

};