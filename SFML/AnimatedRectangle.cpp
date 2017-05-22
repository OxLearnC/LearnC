#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    window.setFramerateLimit(60);

    sf::Texture texture1;
    sf::Texture texture2;
    texture1.loadFromFile("BlackMage.png");
    texture2.loadFromFile("BlackMage2.png");
    
    sf::RectangleShape rect;

    rect.setSize(sf::Vector2f(texture1.getSize().x, texture1.getSize().y));
    rect.setTexture(&texture1);

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
        if (timer > 60) {
            rect.setTexture(&texture1);
            timer = 0;
        }
        if (timer > 30) {
            rect.setTexture(&texture2);
        }

        
        window.display();
    }
    
    return 0;
}