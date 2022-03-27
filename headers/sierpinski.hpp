#include <vector>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
class SierpinskiTriangle {
    private:
    sf::Vector2f resolution;
    public:
    SierpinskiTriangle(sf::Vector2f _resolution);
    void generate(sf::RenderWindow& window,sf::Vector2f points[3],int max_depth);
    sf::Vector2f getMid(sf::Vector2f p1, sf::Vector2f p2);
    sf::Color randomColor();
};