#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game():m_window("Snake Game", sf::Vector2u(800,600)),m_snake(m_world.GetBlockSize()), 
    m_world(m_window.GetWindowSize())
{
    run();
    
}

void Game::run()
{
    m_textbox.Setup(5,14,350,sf::Vector2f(225,0));
    m_textbox.Add("Seeded random number generator with: " + 
        std::to_string(time(NULL)));

    
    score.setFont(m_textbox.GetFont());
    score.setFillColor(sf::Color::White);
    score.setCharacterSize(15);
    score.setPosition(0, 0);


    
    while(!GetWindow()->IsDone()){
        score.setString("Score: "+std::to_string(m_snake.GetScore()));

        HandleInput();
        
        Update();
        Render();
        RestartClock();

    }
}


Game::~Game(){}

void Game::Update()
{
    m_window.Update();
    
    float frameTime = 1.0f / m_snake.GetSpeed(); 

    while (m_elapsed.asSeconds() >= frameTime)
    {
        m_snake.Tick();
        m_world.Update(m_snake);
        if(m_snake.HasLost())
        {
            addText();
            m_snake.Reset();
        }
        
        m_elapsed -= sf::seconds(frameTime); 
    }
}

 void Game::Render()
 {

    m_window.BeginDraw();
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_textbox.Render(*m_window.GetRenderWindow());
    m_window.GetRenderWindow()->draw(score);
    m_window.EndDraw(); // Display.


 }

Window* Game::GetWindow()
{
    return &m_window;
}

sf::Time Game::GetElapsed()
{
    return m_elapsed;
}

void Game::RestartClock()
{
    m_elapsed += m_clock.restart();
}

void Game::addText()
{
    
    if(m_snake.HasLost())
    {
        m_textbox.Add("Game Over, Reset the Score");
        
        m_textbox.Add("The Score: " + std::to_string(m_snake.GetScore()));
    }
    

}

void Game::HandleInput()
{
    
    Direction physicalDir = m_snake.GetPhysicalDirection();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && physicalDir != Direction::Down)
        m_snake.SetDirection(Direction::Up);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && physicalDir != Direction::Up)
        m_snake.SetDirection(Direction::Down);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && physicalDir != Direction::Right)
        m_snake.SetDirection(Direction::Left);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && physicalDir != Direction::Left)
        m_snake.SetDirection(Direction::Right);


}