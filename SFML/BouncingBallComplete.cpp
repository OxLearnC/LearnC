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
	sf::Event e;
	while (window.pollEvent(e)) {
	    if (e.type == sf::Event::Closed) {
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
