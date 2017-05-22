#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    window.setFramerateLimit(60);

    sf::Texture spriteSheet;
    spriteSheet.loadFromFile("SpriteSheet.png");

    
    sf::RectangleShape rect;

    rect.setSize(sf::Vector2f(160, 240));
    rect.setTexture(&spriteSheet);
    rect.setTextureRect(sf::IntRect(0, 0, 400, 600));

    int timer = 0;
    
    while (window.isOpen()) {
        
        // We make sure to process all the events in the queue.
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.clear(sf::Color::Black);

        window.draw(rect);
        
        timer += 1;
        
        if (timer == 120) {
            rect.setTextureRect(sf::IntRect(0*400, 0, 400, 600));
            timer = 0;
        } else if (timer == 90) {
            rect.setTextureRect(sf::IntRect(3*400, 0, 400, 600));
        } else if (timer == 60) {
            rect.setTextureRect(sf::IntRect(2*400, 0, 400, 600));
        } else if (timer == 30) {
            rect.setTextureRect(sf::IntRect(1*400, 0, 400, 600));
        }
        
        window.display();
    }
    
    return 0;
}