#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "SoundHandler.h"

enum GAME_STATE { MAIN_MENU, NEW_GAME, HELP, EXIT };

class MainMenu {
public:
    MainMenu();

    void drawMainMenu(sf::RenderWindow* window);

    void drawHelpPage(sf::RenderWindow* window);

    int buttonPressed(sf::RenderWindow* window,
        const sf::Event::MouseButtonEvent& event);

private:
    
    sf::Texture m_newGameButtonTexture,
                m_helpButtonTexture, 
                m_exitButtonTexture,
                m_mainTexture,
                m_helpPageTexture;
    
    sf::RectangleShape m_mainBackGround;
    sf::RectangleShape m_newGameButton;
    sf::RectangleShape m_helpButton;
    sf::RectangleShape m_exitButton;
    sf::RectangleShape m_helpTexture; 
}; 