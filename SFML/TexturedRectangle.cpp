#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("BlackMage.png");
    
    sf::RectangleShape rect;
    
    // What would happen if we set a different size than the image?
    rect.setSize(sf::Vector2f(texture.getSize().x, texture.getSize().y));
    rect.setTexture(&texture);
    
    // What would happen if we set a color for the rectangle?
    // rect.setFillColor(sf::Color::Red);

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
        
        window.display();
    }
    
    return 0;
}