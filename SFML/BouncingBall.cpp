#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    

    // Let's draw a bouncing ball!
    
    // We will use a sf::CircleShape to represent the ball
    sf::CircleShape ball;
    
    // We can customize the size and color!
    ball.setRadius(50.0);
    ball.setFillColor(sf::Color::Red);
    ball.setOutlineColor(sf::Color::Yellow);
    ball.setOutlineThickness(5.0);
    
    // The CircleShape will also keep track of its own position
    ball.setOrigin(50.0, 50.0);
    ball.setPosition(400, 300);
    
    // We must also keep track of the speed of the ball
    float fall_speed = 0.0;

    // Each iteration of this loop will be a frame
    while (! sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
	// First we clear the screen
	window.clear(sf::Color::Black);
        
	// We accelerate the ball towards the ground
	fall_speed += 0.0002;
	// We update the position of the ball
	ball.move(0, fall_speed);
        
	// If the ball has hit the ground, we make it bounce!
	if (ball.getPosition().y + ball.getRadius() >= 600) {
	    fall_speed = -fall_speed;
	}
        
	// We draw the ball!
	window.draw(ball);

	// Finally, when we are done drawing the frame, we show it with window.display()
	window.display();
	// This is necessary because when we draw, the actual changes are not shown to the player directly until we are done
	// Otherwise, the player could see incomplete frames!
    }
    
    return 0;
}
