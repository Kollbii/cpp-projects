#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{
    sf::RenderWindow Window(sf::VideoMode(1000, 1000), "Gravity");
    sf::CircleShape c1(50);
    c1.setOrigin(50,50);
    c1.setPosition(500, 500);
    c1.setFillColor(sf::Color::Cyan);

    sf::CircleShape c2(30);
    c1.setOrigin(20,20);
    c1.setPosition(500, 100);
    c1.setFillColor(sf::Color::Yellow);

    sf::VertexArray vertices(sf::LinesStrip);
    float mass = 10;
    float vx = 0.1, vy = 0;

    while(Window.isOpen()){
        sf::Event Event;

        while(Window.pollEvent(Event)){
            switch (Event.type){
                case sf::Event::Closed:
                    Window.close();
                    break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            c1.setPosition(sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y);
        }
        float a = c1.getPosition().x - c2.getPosition().x;
        float b = c1.getPosition().y - c2.getPosition().y;
        float acc = mass/(a*a + b*b);
        float accx = acc*a/(sqrt(a*a + b*b));
        float accy = acc*b/(sqrt(a*a + b*b));
        vx += accx;
        vy += accy;
        vertices.append(sf::Vertex(sf::Vector2f(c2.getPosition().x + c2.getRadius()/2, c2.getPosition().y + c2.getRadius()/2)));

        std::cout << vx << "-" << vy << ", ";

        c2.move(vx, vy);
        Window.clear(sf::Color(37,37,37));
        Window.draw(vertices);
        Window.draw(c1);
        Window.draw(c2);
        Window.display();
    }
    return 0;
}

