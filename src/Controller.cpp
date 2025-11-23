#include "Controller.h"

//===============-PUBLICS-================
Controller::Controller() { m_window.setFramerateLimit(60); }

//--------Functions-------

void Controller::run() 
{
    while (m_window.isOpen()) 
    {
        update();
        render();
    }
}


void Controller::update() 
{ 
    pollEvents();
    if (m_gameState == NEW_GAME)
    {

        if (m_board.getCheeseCount() == 0)   
        { 
            m_currentLevel++;
            m_board.resetKeyCount();
            if (!m_board.loadNextLevel(m_currentLevel))
            {
                // if there's no file that means that was the last level
                SoundHandler::getInstance().playSound(Sound_ID::VICTORY);
                SoundHandler::getInstance().playSound(Sound_ID::CLAPPING);
                displayScreen(Screen::FINAL_WIN_SCRN);
                m_window.close();
                return;

            }
            else
            {
                if (m_currentLevel > 1) 
                {
                   SoundHandler::getInstance().playSound(Sound_ID::LEVEL_UP_SOUND);
                   displayScreen(Screen::LEVEL_UP_SCRN);
				   
    
                   m_board.resetTimers();
                }
            }
        }
        
        if (m_board.remainningTime() <= 0)
        {
            SoundHandler::getInstance().playSound(Sound_ID::TIME_UP_SOUND);
            displayScreen(Screen::TIME_UP_SCRN);

            m_board.resetLevelScore();
            m_board.resetKeyCount();
            m_board.loadNextLevel(m_currentLevel);
            m_board.resetTimers();
        }

        if (m_board.getMouseLive() <= 0)
        {
           SoundHandler::getInstance().playSound(Sound_ID::GAME_OVER_SOUND);
           displayScreen(Screen::GAME_OVER_SCRN);
           m_window.close();
        }
        m_board.updateObjects();
        
    }
}

void Controller::pollEvents() 
{
    while (m_window.pollEvent(m_event)) 
    {
        switch (m_event.type)
        {
        case sf::Event::Closed:
            SoundHandler::getInstance().playSound(Sound_ID::SELECTED);

            m_window.close();
            break;
        case sf::Event::KeyPressed:
            if (m_event.key.code == sf::Keyboard::Escape) 
            {
                if (m_gameState == HELP) 
                {
                    m_gameState = MAIN_MENU;
                }
                else 
                {
                    m_window.close();
                }
            }
            break;

        case sf::Event::MouseButtonReleased:
            if (m_gameState == MAIN_MENU) 
            {
                m_gameState = m_mainMenu.buttonPressed(&m_window, m_event.mouseButton);
                if (m_gameState == GAME_STATE::EXIT) 
                {
                    SoundHandler::getInstance().playSound(Sound_ID::SELECTED);
                    m_window.close();
                }
                else if (m_gameState == GAME_STATE::NEW_GAME)
                {
                   SoundHandler::getInstance().playSound(Sound_ID::SELECTED);
                   SoundHandler::getInstance().playSound(Sound_ID::GAME_START);
                }
                else if (m_gameState == GAME_STATE::HELP)
                {
                    SoundHandler::getInstance().playSound(Sound_ID::SELECTED);
                }
            }
            break;

        default:
            break;
        }
    }
}

void Controller::render() 
{
    // clear old screen
    m_window.clear();

    
    switch (m_gameState) 
    {
    case MAIN_MENU:
        m_mainMenu.drawMainMenu(&m_window);
        break;
    case NEW_GAME:
        m_board.renderObjects(&m_window);
        break;
    case HELP:
        m_mainMenu.drawHelpPage(&m_window);
        break;
    default:
        break;
    }
    
    m_window.display();
}




//=============-PRIVATES-=================

void Controller::displayScreen(Screen screen) 
{
    sf::RectangleShape currentScreen;

    switch (screen) 
    {
    case Screen::LEVEL_UP_SCRN:
        currentScreen.setTexture(TextureHandler::getInstance().getObjTexture(Object_ID::LEVEL_UP));
        currentScreen.setPosition(0.f, 0.f);
        currentScreen.setSize(sf::Vector2f(WIDTH, HEIGHT));

        break;
    case Screen::TIME_UP_SCRN:
        currentScreen.setTexture(TextureHandler::getInstance().getObjTexture(Object_ID::TIME_UP));
        currentScreen.setPosition(0.f, 0.f);
        currentScreen.setSize(sf::Vector2f(WIDTH, HEIGHT));
        break;
    case Screen::GAME_OVER_SCRN:
        currentScreen.setTexture(TextureHandler::getInstance().getObjTexture(Object_ID::GAME_OVER));
        currentScreen.setPosition(0.f, 0.f);
        currentScreen.setSize(sf::Vector2f(WIDTH, HEIGHT));

        break;
    case Screen::FINAL_WIN_SCRN:
        currentScreen.setTexture(TextureHandler::getInstance().getObjTexture(Object_ID::FINAL_WIN));
        currentScreen.setPosition(0.f, 0.f);
        currentScreen.setSize(sf::Vector2f(WIDTH, HEIGHT));
        break;
    default:
        break;
    }

    while (true) 
    {
        m_window.clear();
        m_window.pollEvent(m_event);
        m_window.draw(currentScreen);
        m_window.display();
        if (m_event.type == sf::Event::MouseButtonReleased ||
            m_event.key.code == sf::Keyboard::Escape) 
        {
            break;
        }
    }
}
 