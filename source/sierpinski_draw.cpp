#include "../headers/sierpinski_draw.hpp"
#include "../headers/sierpinski.hpp"

int main()
{
    int iter = 1;
    srand(time(0));
    SierpinskiTriangle triangle(sf::Vector2f(WIDTH * SCALE, HEIGHT * SCALE));
    sf::RenderWindow window(sf::VideoMode(WIDTH * SCALE, HEIGHT * SCALE), "Sierpinski triangle viewer");
    sf::Vector2f points[3] = {sf::Vector2f(0, HEIGHT * SCALE), sf::Vector2f(WIDTH * SCALE, HEIGHT * SCALE), sf::Vector2f(WIDTH * SCALE * 0.5, 0)};
    triangle.generate(window, points, iter);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left))
        {
            window.clear();
            triangle.generate(window, points, ++iter);
        }
        window.display();
    }

    return 0;
}