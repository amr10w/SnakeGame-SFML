#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

struct SnakeSegment{
    SnakeSegment(int x,int y):position(x,y){}
    sf::Vector2i position;

};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction{None,Up,Down,Left,Right};

class Snake
{
public:
    Snake(int l_blockSize);
    ~Snake();

    void SetDirection(Direction l_dir);
    Direction GetDirection();
    int GetSpeed();
    sf::Vector2i GetPosition();
    int GetLives();
    int GetScore();
    void IncraseScore();
    bool HasLost();

    void Lose();  // Handle losing here.
    void ToggleLose();

    void Extend();  // Grow the snake.
    void Reset(); // Reset to starting position.

    void Move(); // Movement method.
    void Tick(); // Update method.
    void Cut(int l_segments);  // Method for cutting snake
    void Render(sf::RenderWindow &l_window);
    Direction GetPhysicalDirection();


private:
    void CheckCollision();   // Checking for collisions
    SnakeContainer m_snakeBody; // Segment vector
    int m_size; // Size of the graphics.
    Direction m_dir;// Current direction.
    int m_speed; // Speed of the snake.
    int m_lives; // Lives.
    int m_score; // Score.
    bool m_lost; // Losing state.
    sf::RectangleShape m_bodyRect; // Shape used in rendering.

};

#endif // SNAKE_H
