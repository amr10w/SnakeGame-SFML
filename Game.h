#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "Textbox.h"


class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();
    sf::Time GetElapsed();
    void RestartClock();
    void addText();

private:
    void run();
    
    Window m_window;



    sf::Clock m_clock;
    sf::Time m_elapsed;
    World m_world;
    Snake m_snake;
    Textbox m_textbox;

    sf::Text score;
    
  

};