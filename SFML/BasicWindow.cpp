#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // To display graphics, we need to create a window where we can draw!
    // This is done with the sf::RenderWindow type
    // To use it, we need to #include <SFML/Window.hpp>
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    
    // When creating a window, we provide two parameters
    // The first is a sf::VideoMode with the width and the height of the window
    // The second is simply a string with the name of the window
    
    
    // If we didn't write any more code, the window would open and close immediately
    // Instead we are going to wait until the user presses Escape
    // We can check this with sf::Keyboard::isKeyPressed
    while (! sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        // You can also check whether any other key is pressed by using the right parameter
        
        // For example, if we wanted to check whether the user has pressed the 'a' key:
        // sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            std::cout << "The user pressed A" << std::endl;
        }
    }
    
    return 0;
}
