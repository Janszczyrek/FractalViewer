#include "../headers/mandelbrot_draw.hpp"
#include "../headers/mandelbrot.hpp"

FractalFrame::FractalFrame(sf::Vector2<double> _x_interval, sf::Vector2<double> _y_interval, sf::Vector2f _resolution)
{
    x_interval = _x_interval;
    y_interval = _y_interval;
    resolution = _resolution;
}

sf::Vector2<double> FractalFrame::scaleToFit(sf::Vector2f pixelPos)
{
    pixelPos.y = resolution.y - pixelPos.y; //! (0,0) top right
    double x = (x_interval.x - x_interval.y) * (pixelPos.x / resolution.x) + x_interval.y;
    double y = (y_interval.x - y_interval.y) * (pixelPos.y / resolution.y) + y_interval.y;
    return sf::Vector2<double>(x, y);
}

sf::Vector2f FractalFrame::getResolution() { return resolution; }
int FractalFrame::setResolution(sf::Vector2f _resolution)
{
    resolution = _resolution;
    return 1;
}

sf::VertexArray &FractalFrame::getContents() { return contents; }

sf::Vector2<double> FractalFrame::getXInterval() { return x_interval; }
int FractalFrame::setXInterval(sf::Vector2<double> _x_interval)
{
    x_interval = _x_interval;
    return 1;
}

sf::Vector2<double> FractalFrame::getYInterval() { return y_interval; }
int FractalFrame::setYInterval(sf::Vector2<double> _y_interval)
{
    y_interval = _y_interval;
    return 1;
}

sf::VertexArray &FractalFrame::generateFrame()
{
    contents.clear();
    for (int i = 0; i < resolution.x; i++)
    {
        for (int j = 0; j < resolution.y; j++)
        {
            contents.append(mandelbrot(sf::Vector2f(i, j)));
        }
    }
    return contents;
}

sf::Vertex FractalFrame::mandelbrot(sf::Vector2f coordinates)
{
    sf::Vector2<double> scaledCoordinate = scaleToFit(coordinates);
    sf::Color outputColor(0, 0, 0);
    float x = 0.f;
    float x_temp = 0.f;
    float y = 0.f;
    float i = 0;
    int max_i = 1000;
    while ((x * x + y * y <= 4) && (i < max_i))
    {
        x_temp = x * x - y * y + scaledCoordinate.x;
        y = 2 * x * y + scaledCoordinate.y;
        x = x_temp;
        i++;
    }
    if (i < max_i)
    {
        double log_zn = log(x * x + y * y) / 2;
        double nu = log(log_zn / log(2)) / log(2);
        i = i + 1 - nu;
        sf::Color color1(0.3 * floor(i), 0.5 * floor(i), 0.75 * floor(i));
        sf::Color color2(0.75 * floor(i) + 1, 0.3 * floor(i) + 1, 0.5 * floor(i) + 1);
        float intpart = 0;
        outputColor = lerpRGB(color1, color2, modf(i, &intpart));
    }
    return sf::Vertex(coordinates, outputColor);
}

sf::Color FractalFrame::lerpRGB(sf::Color c1, sf::Color c2, double t)
{
    sf::Color out(
        c1.r + ((c2.r - c1.r) * t),
        c1.g + ((c2.g - c1.g) * t),
        c1.b + ((c2.b - c1.b) * t));
    return out;
}

void FractalFrame::zoom(int quater)
{
    switch (quater)
    {
    case 1:
        setXInterval(
            sf::Vector2<double>(
                x_interval.x,
                ((x_interval.x + x_interval.y) / 2)));
        setYInterval(
            sf::Vector2<double>(
                y_interval.x,
                ((y_interval.x + y_interval.y) / 2)));
        break;
    case 2:
        setXInterval(
            sf::Vector2<double>(
                ((x_interval.x + x_interval.y) / 2),
                x_interval.y));
        setYInterval(
            sf::Vector2<double>(
                y_interval.x,
                ((y_interval.x + y_interval.y) / 2)));
        break;
    case 3:
        setXInterval(
            sf::Vector2<double>(
                ((x_interval.x + x_interval.y) / 2),
                x_interval.y));
        setYInterval(
            sf::Vector2<double>(
                ((y_interval.x + y_interval.y) / 2),
                y_interval.y));
        break;
    case 4:
        setXInterval(
            sf::Vector2<double>(
                x_interval.x,
                ((x_interval.x + x_interval.y) / 2)));
        setYInterval(
            sf::Vector2<double>(
                ((y_interval.x + y_interval.y) / 2),
                y_interval.y));
        break;
    default:
        break;
        //! Error
    }
}
