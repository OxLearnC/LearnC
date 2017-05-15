#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    window.setFramerateLimit(60);

    sf::CircleShape ball;
    ball.setRadius(50.0);
    ball.setFillColor(sf::Color::Red);
    ball.setOutlineColor(sf::Color::Yellow);
    ball.setOutlineThickness(5.0);
    
    ball.setOrigin(50.0, 50.0);
    ball.setPosition(400, 300);
    
    float fall_speed = 0.0;

    while (window.isOpen()) {
        
        // We make sure to process all the events in the queue.
        sf::Event e;
        // window.pollEvent extracts an event from the event queue of the window
        // You need to give it an event as an argument
        // It will return either true or false, depending on whether there were any events in the queue
        while (window.pollEvent(e)) {
            // We can check what kind of event it is by looking at e.type
            if (e.type == sf::Event::Closed) {
                // sf::Event::Closed means the user has pressed the close button
                window.close();
            }
        }
        
        window.clear(sf::Color::Black);
        
        fall_speed += 0.1;
        ball.move(0, fall_speed);
        
        if (ball.getPosition().y + ball.getRadius() >= 600) {
            fall_speed = -fall_speed;
        }
        
        window.draw(ball);

        window.display();
    }
    
    return 0;
}
