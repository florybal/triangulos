#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{
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

    //tem que fazer a distancia de AB, AC, CBS
    DAC = sqrt(pow(Ax-Cx,2) +  pow(Ay-Cy,2) ); //a
    DBC = sqrt(pow(Bx-Cx,2) +  pow(By-Cy,2) ); //b
    DAB = sqrt(pow(Ax-Bx,2) +  pow(Ay-By,2) ); //c

    if((DAB + DBC > DAC) && (DAC + DAB > DBC) && (DBC + DAB > DAC))
    {
        triangulo = true;
    }else{
        triangulo = false;
    }

    std::cout <<"A: " << DAC << std::endl;
    std::cout <<"B: " << DBC << std::endl;
    std::cout <<"C: " << DAB << std::endl;
    std::cout << triangulo << std::endl;

    // set its texture coordinates
    //vertex.texCoords = sf::Vector2f(100.f, 100.f);
    sf::VertexArray triangle(sf::Triangles, 3);

    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(Ax, Ay);
    triangle[1].position = sf::Vector2f(Bx, By);
    triangle[2].position = sf::Vector2f(Cx, Cy);

    // define the color of the triangle's points
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;

    // no texture coordinates here, we'll see that later

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
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