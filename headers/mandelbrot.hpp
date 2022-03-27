#include <SFML/Graphics.hpp>
class FractalFrame {
    private:
    sf::Vector2f resolution;
    sf::VertexArray contents;
    sf::Vector2<double> x_interval; //! x- max y- min
    sf::Vector2<double> y_interval; //!

    sf::Vector2<double> scaleToFit(sf::Vector2f pixelPos);

    sf::Vertex mandelbrot(sf::Vector2f coordinates);

    sf::Color lerpRGB(sf::Color c1,sf::Color c2, double t);

    public:
    sf::Vector2f getResolution();
    int setResolution(sf::Vector2f _resolution);

    int setXInterval(sf::Vector2<double> _x_interval);
    sf::Vector2<double> getXInterval();

    int setYInterval(sf::Vector2<double> _y_interval);
    sf::Vector2<double> getYInterval();

    sf::VertexArray& getContents();
    sf::VertexArray& generateFrame();
    FractalFrame(sf::Vector2<double> _x_interval, sf::Vector2<double> _y_interval, sf::Vector2f _resolution);

    void zoom(int quater);
};