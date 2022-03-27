#include "../headers/mandelbrot_draw.hpp"
#include "../headers/mandelbrot.hpp"
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
    FractalFrame frame(sf::Vector2<double>(MAX_X, MIN_X), sf::Vector2<double>(MAX_Y, MIN_Y), sf::Vector2f(WIDTH * SCALE, HEIGHT * SCALE));
    sf::RenderWindow window(sf::VideoMode(WIDTH * SCALE, HEIGHT * SCALE), "Mandelbrot set viewer");
    window.draw(frame.generateFrame());
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
            frame.zoom(checkQuater(mousePos));
            window.clear();
            window.draw(frame.generateFrame());
        }
        window.display();
    }

    return 0;
}