#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const int map_height = 20;
const int map_width = 20;

class ResourceManager
{
public:
    ResourceManager()
    {
        map.loadFromFile("Floor.png");

        enemies.loadFromFile("Enemies.png");

        player.loadFromFile("Player.png");
        
        sword.loadFromFile("Sword.wav");
    }

    sf::Texture player, enemies, map;
    sf::SoundBuffer sword;
};

ResourceManager manager;

const int tile_size = 32;
sf::IntRect getMapRect(int i, int j)
{
    return sf::IntRect(i * 16, j * 16, 16, 16);
}

void drawMap(sf::RenderWindow& window)
{
    for (int i = 0; i < map_width; i++) {
        for (int j = 0; j < map_height; j++) {
            sf::RectangleShape square;
            square.setTexture(&manager.map);
            square.setSize(sf::Vector2f(tile_size, tile_size));

            if (i == 0 && j == 0) {
                square.setTextureRect(getMapRect(0, 6));
            } else if (i == 0 && j == map_height - 1) {
                square.setTextureRect(getMapRect(0, 8));
            } else if (i == map_width - 1 && j == 0) {
                square.setTextureRect(getMapRect(2, 6));
            } else if (i == map_width - 1 && j == map_height - 1) {
                square.setTextureRect(getMapRect(2, 8));
            } else if (i == 0) {
                square.setTextureRect(getMapRect(0, 7));
            } else if (j == 0) {
                square.setTextureRect(getMapRect(1, 6));
            } else if (i == map_width - 1) {
                square.setTextureRect(getMapRect(2, 7));
            } else if (j == map_height - 1) {
                square.setTextureRect(getMapRect(1, 8));
            } else {
                square.setTextureRect(getMapRect(1, 7));
            }

            square.setPosition(i * tile_size, j * tile_size);
            window.draw(square);
        }
    }
}

class Player
{
public:
    Player(int position_x, int position_y)
    {
        this->shape.setPosition(sf::Vector2f(position_x * tile_size, position_y * tile_size));
        this->shape.setTexture(&manager.player);
        this->shape.setSize(sf::Vector2f(tile_size, tile_size));
        this->timer = 0;
        this->animation_stage = 0;
        this->setSprite(0, 0);
        this->sword.setBuffer(manager.sword);
    }
    
    virtual void update()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->getShape().move(0, -1);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->getShape().move(0, 1);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->getShape().move(-1, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->getShape().move(1, 0);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (this->sword.getStatus() != sf::Sound::Playing) {
                this->sword.play();
            }
        }
        
        timer += 1;
    }
    
    virtual sf::RectangleShape& getShape()
    {
        return this->shape;
    }

protected:
  
    static const int sprite_height = 16;
    static const int sprite_width = 16;
    static const int gap_height = 14;
    static const int gap_width = 14;
    
    int timer;
    int animation_stage;

    sf::RectangleShape shape;
    
    sf::Sound sword;
    
    virtual sf::IntRect getSpriteRect(int i, int j)
    {
        return sf::IntRect(i * sprite_width + i * gap_width, j * sprite_height + j * gap_height, sprite_width, sprite_height);
    }
    
    virtual void setSprite(int i, int j)
    {
        this->shape.setTextureRect(getSpriteRect(i, j));
    }
};

class Enemy
{
public:
    Enemy(int initial_x, int initial_y, int animation_stage)
    {
        this->shape.setPosition(initial_x * tile_size, initial_y * tile_size);
        this->shape.setSize(sf::Vector2f(tile_size, tile_size));
        this->shape.setTexture(&manager.enemies);
        this->timer = 0;
        this->animation_stage = animation_stage;
        this->setSprite(animation_stage, 0);
    }

    virtual void update()
    {
        timer += 1;
        if (timer > 60) {
            this->setSprite(animation_stage, 0);
            timer = 0;
        } else if (timer > 30) {
            this->setSprite(animation_stage, 1);
        }
    }
    
    virtual sf::RectangleShape& getShape() {
        return shape;
    }

protected:
    static const int sprite_height = 16;
    static const int sprite_width = 16;
    static const int gap_height = 14;
    static const int gap_width = 14;
    
    int timer;
    int animation_stage;

    sf::RectangleShape shape;
    virtual sf::IntRect getSpriteRect(int i, int j)
    {
        return sf::IntRect(i * sprite_width + i * gap_width, j * sprite_height + j * gap_height, sprite_width, sprite_height);
    }
    
    virtual void setSprite(int i, int j)
    {
        this->shape.setTextureRect(getSpriteRect(i, j));
    }
};

class VerticalEnemy : public Enemy
{
public:
    VerticalEnemy(int initial_x, int initial_y, int final_y) : Enemy(initial_x, initial_y, 0)
    {
        this->initial_y = initial_y * tile_size;
        this->final_y = final_y * tile_size;
        this->direction = 1;
    }
    
    virtual void update()
    {
        sf::Vector2f position = this->getShape().getPosition();
        
        if (position.y > this->final_y) {
            direction = -1;
            this->animation_stage = 2;
        } else if (position.y < this->initial_y) {
            direction = 1;
            this->animation_stage = 0;
        }
        
        this->getShape().move(0, this->direction);
        
        Enemy::update();
    }
    
protected:
    int direction;
    int initial_y;
    int final_y;
};

class HorizontalEnemy : public Enemy
{
public:
    HorizontalEnemy(int initial_x, int initial_y, int final_x) : Enemy(initial_x, initial_y, 3)
    {
        this->initial_x = initial_x * tile_size;
        this->final_x = final_x * tile_size;
        this->direction = 1;
    }
    
    virtual void update()
    {
        sf::Vector2f position = this->getShape().getPosition();
        
        if (position.x > this->final_x) {
            direction = -1;
            this->animation_stage = 1;
        } else if (position.x < this->initial_x) {
            direction = 1;
            this->animation_stage = 3;
        }
        
        this->getShape().move(this->direction, 0);
        
        Enemy::update();
    }
    
protected:
    int direction;
    int initial_x;
    int final_x;
};


int main()
{
    srand(time(NULL)); // This is used to set up the random number generator
    sf::RenderWindow window(sf::VideoMode(tile_size * map_width, tile_size * map_height), "Rogue");
    window.setFramerateLimit(60);

    Player player(1, 1);
    HorizontalEnemy e1(10, 10, 15);
    VerticalEnemy e2(3, 3, 10);
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        drawMap(window);
        
        e1.update();
        e2.update();
        player.update();
        
        window.draw(e1.getShape());
        window.draw(e2.getShape());
        window.draw(player.getShape());

        window.display();
    }
}