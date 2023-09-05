#include "triangulo.h"

struct{
    bool ehTriangulo;
    double DAC, DBC, DAB;
    float Ax, Ay, Bx,  By, Cx, Cy;
    float baricentro_x, baricentro_y;
    float Mac, Mab, Mbc;
    float Pab_x, Pab_y, Pac_x, Pac_y, Pbc_x, Pbc_y;
}triangulo;
    
void triangle::run()
{   
    //criando a janela
    sf::RenderWindow* _window(sf::VideoMode(800, 600), "triangulos");
    desenha();
    verificaTriangulo();
    processEvent();
}

void triangle::processEvent()
{
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if ((event.type == sf::Event::Closed) or 
            (event.type == sf::Event::keyPressing and event.key.code==sf::keyboard::Escape))
                _window.close();
        }

        // clear the window with black color
        _window.clear(sf::Color::Black);

        // draw everything here...
        _window.draw(triangle);

        // end the current frame
        _window.display();
    }

}

void triangle::desenha()
{
    //instanciando o tamanho de um vetor do tipo triangulo
    sf::VertexArray triangle(sf::Triangles, 3);

    //definindo sua posição no plano
    triangle[0].position = sf::Vector2f(Ax, Ay);
    triangle[1].position = sf::Vector2f(Bx, By);
    triangle[2].position = sf::Vector2f(Cx, Cy);

    //cor
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;

}
void triangle::distance()
{
    //distancias dos pontos AB, AC, CB
    DAC = sqrt(pow(Ax-Cx,2) +  pow(Ay-Cy,2) ); //a
    DBC = sqrt(pow(Bx-Cx,2) +  pow(By-Cy,2) ); //b
    DAB = sqrt(pow(Ax-Bx,2) +  pow(Ay-By,2) ); //c

    //mostrando as distancias calculadas
    std::cout <<"A: " << DAC << std::endl;
    std::cout <<"B: " << DBC << std::endl;
    std::cout <<"C: " << DAB << std::endl;
    std::cout << triangulo << std::endl;

}
void triangle::mediatriz()
{
    Mac = DAC / 2; //a
    Mbc = DBC / 2; //b
    Mab = DAB / 2; //c
}

void triangle::baricentro()
{
    baricentro_x = Ax + Bx + Cx /3; 
    baricentro_y = Ay + By + Cy /3;
}

bool triangle::triangulo()
{
    //coordenadas em pixels na tela
    std::cout << "De as coordenadas do triangulo \n A:" << std::endl;
    std::cin >> Ax >> Ay;
    std::cout << "B" << std::endl;
    std::cin >> Bx >> By;
    std::cout << "C" << std::endl;
    std::cin >> Cx >> Cy;

    //condição para ser um triangulo
    auto condicao = (DAB + DBC > DAC) && (DAC + DAB > DBC) && (DBC + DAB > DAC);

    if(!condicao)
        ehTriangulo = false;
}

void triangle::ponto_med()
{
    Pac_x = Ax + Cx / 2; //reta a
    Pac_y = Ay + Cy / 2;

    Pbc_y = By + Cy / 2; //reta b
    Pbc_x = Bx + Cx / 2;

    Pab_x = Ax + Bx / 2; //reta c
    Pab_y = Ay + By / 2;

}

void triangle::equacoes()
{
    std::cout<<"Equações da reta: "<<std::endl;

    // y -y1/ yb - ya = x - x1/ x2 - x1

    // equação da reta A pelo seguemento AC = A
    std::cout << "A:" <<std::endl << (Cx - Ax)*(Ay) <<  "y"
    << - (Cy - Ay)*(Cx) << "x" <<std::endl;

    //equação da reta BC = B 
    std::cout << "B:" <<std::endl<< (Cx - Bx)*(- By)<<"y" 
    << - (Cy - By)*(Cx) << "x" <<std::endl;

    // equação da reta A pelo seguemento AB = C
    std::cout << "C:" <<std::endl << (Bx - Ax)*(Ay)<<"y"
    << - (By - Ay)*(Ax)<<"x" <<std::endl; 
    
}