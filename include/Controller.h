#pragma once

#include <iostream>

#include "Board.h"
#include "MainMenu.h"

enum Screen { LEVEL_UP_SCRN, TIME_UP_SCRN, GAME_OVER_SCRN, FINAL_WIN_SCRN};

const float WIDTH = 900.f;
const float HEIGHT = 950.f;

class Controller 
{
public:
    Controller();

    void run();

    void pollEvents();

    void update();

    void render();

private:
    // Variables
    sf::RenderWindow m_window =
        sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Mouse vs Cats",
            sf::Style::Close | sf::Style::Titlebar);

    sf::Event m_event;
    int m_gameState = 0;
    int m_currentLevel = 0;
    sf::RectangleShape m_wonScreen;
    Board m_board; 
    MainMenu m_mainMenu;

    // Private Functions
    void displayScreen(Screen screen);
};
 