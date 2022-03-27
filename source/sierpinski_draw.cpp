#include "../headers/sierpinski_draw.hpp"
#include "../headers/sierpinski.hpp"
int checkQuater(sf::Vector2<double> point)
{
    if ((point.x > 0.5 * WIDTH * SCALE) && (point.y < 0.5 * HEIGHT * SCALE))
        return 1;
    if ((point.x < 0.5 * WIDTH * SCALE) && (point.y < 0.5 * HEIGHT * SCALE))
        return 2;
    if ((point.x < 0.5 * WIDTH * SCALE) && (point.y > 0.5 * HEIGHT * SCALE))
        return 3;
    if ((point.x > 0.5 * WIDTH * SCALE) && (point.y > 0.5 * HEIGHT * SCALE))
        return 4;
    return -1;
}

int main()
{
    srand(time(0));
    SierpinskiTriangle triangle(sf::Vector2f(WIDTH*SCALE,HEIGHT*SCALE));
    sf::RenderWindow window(sf::VideoMode(WIDTH * SCALE, HEIGHT * SCALE), "Sierpinski triangle viewer");
    sf::Vector2f points[3] = {sf::Vector2f(0,HEIGHT*SCALE),sf::Vector2f(WIDTH*SCALE,HEIGHT*SCALE),sf::Vector2f(WIDTH*SCALE*0.5,0)};
    triangle.generate(window,points,5);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2<double> mousePos{sf::Mouse::getPosition(window)};
            window.clear();
        }
        window.display();
    }

    return 0;
}