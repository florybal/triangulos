#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>

int main()
{ 
    //variaveis
    bool triangulo;
    double DAC, DBC, DAB;
    float Ax, Ay, Bx,  By, Cx, Cy;
    
    //coordenadas em pixels na tela
    std::cout << "De as coordenadas do triangulo \n A:" << std::endl;
    std::cin >> Ax >> Ay;
    std::cout << "B" << std::endl;
    std::cin >> Bx >> By;
    std::cout << "C" << std::endl;
    std::cin >> Cx >> Cy;

    //distancias dos pontos AB, AC, CBS
    DAC = sqrt(pow(Ax-Cx,2) +  pow(Ay-Cy,2) ); //a
    DBC = sqrt(pow(Bx-Cx,2) +  pow(By-Cy,2) ); //b
    DAB = sqrt(pow(Ax-Bx,2) +  pow(Ay-By,2) ); //c

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

    //condição de existencia para ser triangulos
    if((DAB + DBC > DAC) && (DAC + DAB > DBC) && (DBC + DAB > DAC))
    {
        triangulo = true;
    }else{
        triangulo = false;
    }

    //mostrando as distancias calculadas
    std::cout <<"A: " << DAC << std::endl;
    std::cout <<"B: " << DBC << std::endl;
    std::cout <<"C: " << DAB << std::endl;
    std::cout << triangulo << std::endl;

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

    //criando a janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;

}