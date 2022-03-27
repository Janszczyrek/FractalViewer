#include "../headers/sierpinski.hpp"

SierpinskiTriangle::SierpinskiTriangle(sf::Vector2f _resolution)
{
    resolution = _resolution;
}

void SierpinskiTriangle::generate(sf::RenderWindow &window, sf::Vector2f points[3], int max_depth)
{
    sf::VertexArray triangle(sf::Triangles,3);
    triangle[0].position = sf::Vector2f(points[0].x,points[0].y);
    triangle[1].position = sf::Vector2f(points[1].x,points[1].y);
    triangle[2].position = sf::Vector2f(points[2].x,points[2].y);
    // if(md>) {
         triangle[0].color = randomColor();
         triangle[1].color = randomColor();
         triangle[2].color = randomColor();
    // }
    if(max_depth==1) window.draw(triangle);
    if(max_depth>0) {
        sf::Vector2f newPoints1[3];
        newPoints1[0] = points[0];
        newPoints1[1] = getMid(points[0],points[1]);
        newPoints1[2] = getMid(points[0],points[2]);
        generate(window, newPoints1,max_depth-1);

        sf::Vector2f newPoints2[3];
        newPoints2[0] = getMid(points[0],points[1]);
        newPoints2[1] = points[1];
        newPoints2[2] = getMid(points[1],points[2]);
        generate(window, newPoints2,max_depth-1);

        sf::Vector2f newPoints3[3];
        newPoints3[0] = getMid(points[0],points[2]);
        newPoints3[1] = getMid(points[1],points[2]);
        newPoints3[2] = points[2];
        generate(window, newPoints3,max_depth-1);
    }
}
sf::Vector2f SierpinskiTriangle::getMid(sf::Vector2f p1, sf::Vector2f p2)
{
    return sf::Vector2f(
        (p1.x+p2.x)/2,
        (p1.y+p2.y)/2
    );
}
sf::Color SierpinskiTriangle::randomColor() {
    int random = rand() % 8;
    sf::Color colors[8] = {
        sf::Color::Black,
        sf::Color::Blue,
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Yellow,
        sf::Color::White,
        sf::Color::Cyan,
        sf::Color::Magenta,
    };
    return colors[random];
}