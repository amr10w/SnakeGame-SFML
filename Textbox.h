#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>

using MessageContainer = std::vector<std::string>;

class Textbox{
public:
    Textbox();
    Textbox(int l_visable,int l_charSize,int l_width,
        sf::Vector2f _screenPos);
    ~Textbox();

    void Setup(int l_visable,int l_charSize,int l_width,
        sf::Vector2f _screenPos);

    void Add(std::string l_message);
    void Clear();

    void Render(sf::RenderWindow& l_window);

    const sf::Font& GetFont();
    

private:
    MessageContainer m_messages;
    int m_numVisable;

    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_content;



};


#endif